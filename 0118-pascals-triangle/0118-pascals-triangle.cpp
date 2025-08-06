class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> sample;
        for(int i=0; i<numRows; i++){
            int res = 1;
            for(int j = 0; j <= i; j++){
                sample.push_back(res);
                res *= i-j;
                res /= j+1;
            }
            ans.push_back(sample);
            sample.clear();
        }
        return ans;
    }
};