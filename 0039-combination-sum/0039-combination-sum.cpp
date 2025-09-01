class Solution {
public:

    void sum(vector<vector<int>> &ans, vector<int> &candidates, int i, int target, vector<int> op){
        if(target<=0){
            if(target==0){
                ans.push_back(op);
            }
            return;
        }
        if(i>=candidates.size()) return;
        vector<int> temp = op;
        temp.push_back(candidates[i]);
        sum(ans, candidates, i, target-candidates[i], temp);
        sum(ans, candidates, i+1, target, op);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sum(ans, candidates, 0, target, {});
        return ans;
    }
};