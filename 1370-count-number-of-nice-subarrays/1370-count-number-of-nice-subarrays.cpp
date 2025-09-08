class Solution {
public:
    int totalsum(vector<int> &nums, int goal){
        if(goal<0) return 0;
        int l=0, r=0, sum=0, count=0;
        while(r<nums.size()){
            if(nums[r]%2==1) sum++;
            while(sum>goal){
                if(nums[l]%2==1)
                    sum--;
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return totalsum(nums, k)-totalsum(nums, k-1);
    }
};