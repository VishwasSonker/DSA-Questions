class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> leftpass(n, 1); 

        for(int i=1; i<n; i++){
            if(ratings[i-1]<ratings[i]){
                leftpass[i]=leftpass[i-1]+1;
            }
        }
        int ans=leftpass[n-1];
        for(int i=n-2; i>=0; i--){
            if(ratings[i+1]<ratings[i]){
                leftpass[i]=max(leftpass[i], leftpass[i+1]+1);
            }
            ans+=leftpass[i];
        }
        return ans;
    }
};