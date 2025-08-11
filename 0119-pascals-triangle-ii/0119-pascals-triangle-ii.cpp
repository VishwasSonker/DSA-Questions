class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long res=1;
        for(long long i=0; i<=rowIndex; i++){
            ans.push_back(res);
            res*=rowIndex-i;
            res/=i+1;
        }
        return ans;
    }
};