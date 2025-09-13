class Solution {
public:
    int jump(vector<int>& nums) {
        int count=0;
        int n= nums.size();
        int l=0, r=0;
        while(r<n-1){
            int far = 0;
            for(int i=l; i<=r; i++){
                far=max(far, i+nums[i]);
            }
            l=r+1;
            r=far;
            count++;
        }
        return count;
    }
};