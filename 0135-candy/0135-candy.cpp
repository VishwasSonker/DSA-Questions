class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> leftpass(n, 1);
        vector<int> rightpass(n, 1); 

        for(int i=1; i<n; i++){
            if(ratings[i-1]<ratings[i]){
                leftpass[i]=leftpass[i-1]+1;
            }
            if(ratings[n-i]<ratings[n-i-1]){
                rightpass[n-i-1]=rightpass[n-i]+1;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans+=max(leftpass[i], rightpass[i]);
        }
        return ans;
    }
};