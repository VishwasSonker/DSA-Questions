class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=0;
        int maxi=0;
        for(int num : nums){
            if(num==0) n=0;
            n+=num;
            maxi = max(maxi, n);
        }
        return maxi;
    }
};