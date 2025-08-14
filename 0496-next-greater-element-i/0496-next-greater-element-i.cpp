class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        stack<int> st;
        for(int i=nums2.size()-1; i>=0; i--){
            if(st.empty()){
                mpp.insert({nums2[i], -1});
                st.push(nums2[i]);
            }else if(nums2[i]<st.top()){
                mpp.insert({nums2[i], st.top()});
                st.push(nums2[i]);
            }else{
                while(!st.empty()&&nums2[i]>st.top()){
                    st.pop();
                }
                if(st.empty()){
                    mpp.insert({nums2[i], -1});
                    st.push(nums2[i]);
                }else{
                    mpp.insert({nums2[i], st.top()});
                    st.push(nums2[i]);
                }
            }
        }
        vector<int>ans;
        for(int i=0; i<nums1.size(); i++){
            int a = mpp[nums1[i]];
            ans.push_back(a);
        }
        return ans;
    }
};