class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro = nums[0];
        int n = nums.size();
        for(int i=1, imax=nums[0], imin=nums[0]; i<n; i++){
            if(nums[i]<0) swap(imax, imin);
            imax = max(nums[i], imax*nums[i]);
            imin = min(nums[i], imin*nums[i]);
            maxpro = max(maxpro, imax);
        }
        return maxpro;
    }
};