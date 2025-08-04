class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(count==0){
                candidate = nums[i];
                count=1;
            }else if(candidate == nums[i]){
                count++;
            }else{
                count--;
            }
        }

        // count = 0;
        // for(int num : nums){
        //     if(candidate == num) count ++;
        // }

        return candidate;
    }
};