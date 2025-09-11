class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l=0, r=0;
        int count=0;
        while(r<s.size()){
            if(l<g.size()&&s[r]>=g[l]){
                count++;
                l++;
            }
            r++;
        }
        return count;
    }
};