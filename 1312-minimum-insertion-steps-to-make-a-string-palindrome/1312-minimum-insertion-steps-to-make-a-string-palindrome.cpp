class Solution {
public:
    int lcs(string& a, string& b){
        int n = a.size();
        int m = b.size();
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }

    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        int lps = lcs(s, t);
        return n-lps;
    }
};