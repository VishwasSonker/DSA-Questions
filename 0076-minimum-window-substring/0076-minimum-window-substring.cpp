class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256]={0};
        for(char a : t){
            hash[a]++;
        }
        int sindex=-1, count=0;
        int minlen=INT_MAX;
        int l=0, r=0;
        while(r<s.size()){
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;
            while(count==t.size()){
                if((r-l+1)<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return sindex==-1?"":s.substr(sindex, minlen);
    }
};