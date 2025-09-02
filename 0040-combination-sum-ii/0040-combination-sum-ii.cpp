class Solution {
public:

    void sum(vector<vector<int>> &ans, vector<int> &candidates, int target, int start, vector<int> &op){
        if(target==0){
            ans.push_back(op);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if(i>start&&candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            op.push_back(candidates[i]);
            sum(ans, candidates, target-candidates[i], i+1, op);
            op.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        sort(candidates.begin(), candidates.end());
        sum(ans, candidates, target, 0, op);
        return ans;
    }
};