class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long maxfreq = 0, l=0, r=0, total=0, n=nums.size();
        for(r=0; r<n; r++){
            total+=nums[r];
            while(l+1<=r && (nums[r]*(r-l+1))>total+k){
                total-=nums[l];
                l++;
            }
            maxfreq = max(maxfreq, r-l+1);
        }
        return maxfreq;
    }
};