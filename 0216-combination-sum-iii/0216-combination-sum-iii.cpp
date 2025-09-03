class Solution {
public:

    void sum(int num, vector<vector<int>> &ans, int target, int k, vector<int> &op){
        if(target==0 && op.size()==k){
            ans.push_back(op);
            return;
        }
        if(target<0||op.size()>k) return;

        for(int i=num; i<10; i++){
            if(op.size()+(9-i+1)<k) return;
            op.push_back(i);
            sum(i+1, ans, target-i, k, op);
            op.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> op;
        sum(1, ans, n, k, op);
        return ans;
    }
};