class Solution {
public:

    void sum(int num, vector<vector<int>> &ans, int target, int k, vector<int> op){
        if(num>9){
            if(target==0&&op.size()==k){
                ans.push_back(op);
            }
            return;
        }
        if(op.size()>k) return;
        op.push_back(num);
        sum(num+1, ans, target-num, k, op);
        op.pop_back();
        sum(num+1, ans, target, k, op);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> op;
        sum(1, ans, n, k, op);
        return ans;
    }
};