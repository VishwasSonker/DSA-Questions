class Solution {
public:

    int totalsum(vector<int> &nums, int goal){
        if(goal<0) return 0;
        unordered_map<int, int> mpp;
        int l=0, r=0, count=0;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>goal){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return totalsum(nums, k)-totalsum(nums, k-1);
    }
};