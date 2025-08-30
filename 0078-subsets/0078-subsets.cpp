class Solution {
public:

    void subset(vector<int> nums, vector<vector<int>> &ans, int i, vector<int> op){
        if(i==nums.size()){
            ans.push_back(op);
            return;
        }
        subset(nums, ans, i+1, op);
        op.push_back(nums[i]);
        subset(nums, ans, i+1, op);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        subset(nums, ans, 0, {});
        return ans;
    }
};