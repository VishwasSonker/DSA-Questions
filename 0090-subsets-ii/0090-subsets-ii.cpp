class Solution {
public:

    void subsets(vector<int> &nums, vector<vector<int>> &ans, int start, vector<int> &op){
        ans.push_back(op);

        for(int i=start; i<nums.size(); i++){
            if(i>start&&nums[i]==nums[i-1]) continue;
            op.push_back(nums[i]);
            subsets(nums, ans, i+1, op);
            op.pop_back();           
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> op;
        subsets(nums, ans, 0, op);
        return ans;
    }
};