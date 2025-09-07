class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int a=1;
        if(n%2==0){
            int i=0;
            while(i<n){
                ans.push_back(a);
                ans.push_back(-a);
                i+=2;
                a++;
            }
        }else{
            ans.push_back(0);
            int i=0;
            while(i<n-1){
                ans.push_back(a);
                ans.push_back(-a);
                i+=2;
                a++;
            }
        }
        return ans;
    }
};