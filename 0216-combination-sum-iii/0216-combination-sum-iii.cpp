class Solution {
public:

    void sum(vector<int> &numbers, vector<vector<int>> &ans,int i, int target, int k, vector<int> op){
        if(i==numbers.size()){
            if(target==0&&op.size()==k){
                ans.push_back(op);
            }
            return;
        }
        op.push_back(numbers[i]);
        sum(numbers, ans, i+1, target-numbers[i], k, op);
        op.pop_back();
        sum(numbers, ans, i+1, target, k, op);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> op;
        sum(numbers, ans, 0, n, k, op);
        return ans;
    }
};