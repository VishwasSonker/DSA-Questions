class Solution {
public:

    void sum(vector<vector<int>> &ans, vector<int> &candidates, int i, int target, vector<int> &op){
        if(target<=0){
            if(target==0){
                ans.push_back(op);
            }
            return;
        }
        if(i>=candidates.size()) return;
        op.push_back(candidates[i]);
        sum(ans, candidates, i, target-candidates[i], op);
        op.pop_back();
        sum(ans, candidates, i+1, target, op);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        sum(ans, candidates, 0, target, op);
        return ans;
    }
};