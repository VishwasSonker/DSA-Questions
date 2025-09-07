class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int l=0, r=0;
        int n=s.length();
        int maxlen=0;
        while(l<n&&r<n){
            if(mpp.count(s[r])){
                l = max(l, mpp[s[r]] + 1);
            }
            mpp[s[r]]=r;
            int len=r-l+1;
            maxlen=max(maxlen, len);
            r++;
        }
        return maxlen;
    }
};