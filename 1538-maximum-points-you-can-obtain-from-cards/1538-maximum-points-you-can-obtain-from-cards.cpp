class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum = 0;
        for(int i=0; i<k; i++){
            sum+=cardPoints[i];
        }
        int maxsum=sum;
        int l=k-1;
        int r=n-1;
        while(l>=0){
            sum-=cardPoints[l];
            sum+=cardPoints[r];
            maxsum=max(maxsum, sum);
            l--;
            r--;
        }
        return maxsum;
    }
};