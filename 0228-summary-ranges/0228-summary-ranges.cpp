class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;

        int start = nums[0];
        
        for (int i = 1; i <= nums.size(); i++) {
            // Check if we're at the end or the sequence breaks
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1])
                    res.push_back(to_string(start)); // Single number
                else
                    res.push_back(to_string(start) + "->" + to_string(nums[i - 1])); // Range
                if (i < nums.size()) start = nums[i]; // Start new range
            }
        }
        return res;
    }
};