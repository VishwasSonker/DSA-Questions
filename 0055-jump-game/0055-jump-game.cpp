class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps=0;
        int n=nums.size();
        int l=n-2, r=n-1;
        while(l>=0){
            steps=r-l;
            if(steps<=nums[l]){
                r=l;
            }
            l--;
        }
        return r==0;
    }
};