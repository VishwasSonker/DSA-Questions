class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mpp;
        int count=0;
        int l=0;
        int n=s.length();
        for(int r=0; r<n; r++){
            mpp[s[r]]++;
            while(mpp['a']>0&&mpp['b']>0&&mpp['c']>0){
                count+=(n-r);
                mpp[s[l]]--;
                l++;
            }
        }
        return count;
    }
};