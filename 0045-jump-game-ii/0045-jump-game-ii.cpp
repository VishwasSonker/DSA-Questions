class Solution {
public:
    int jump(vector<int>& nums) {
        int count=0;
        int n= nums.size();
        int r=n-1;
        while(r>0){
            for(int l=0; l<r; l++){
                if(l+nums[l]>=r){
                    count++;
                    r=l;
                    break;
                }
            }
        }
        return count;
    }
};