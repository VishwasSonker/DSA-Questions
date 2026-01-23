class Solution {
public:
    int lcs(string& x, string& y, int n, int m, vector<vector<int>>& memo) {
        if (n == 0 || m == 0)
            return 0;

        if(memo[n-1][m-1]!=-1)
            return memo[n-1][m-1];
        
        if (x[n - 1] == y[m - 1])
            memo[n-1][m-1] = 1 + lcs(x, y, n - 1, m - 1, memo);
        else
            memo[n-1][m-1] = max(lcs(x, y, n, m - 1, memo), lcs(x, y, n - 1, m, memo));

        return memo[n-1][m-1];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return lcs(text1, text2, n, m, memo);
    }
};