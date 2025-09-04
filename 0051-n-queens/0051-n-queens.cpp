class Solution {
public:

    bool issafe(vector<vector<char>> &board, int row, int col, int n){
        // checking left upper diagonal
        for(int i=row, j=col; i>=0&&j>=0; i--, j--){
            if(board[i][j]=='Q') return false;
        }
        // checking upper row
        for(int i=row; i>=0; i--){
            if(board[i][col]=='Q') return false;
        }
        // checking right upper diagonal
        for(int i=row, j=col; i>=0&&j<n; i--, j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }

    void helper(int row, vector<vector<string>> &ans, vector<vector<char>> &board, int n){
        if(row==n){
            vector<string> str;
            for(int i=0; i<n; i++){
                string s(board[i].begin(), board[i].end());
                str.push_back(s);
            }
            ans.push_back(str);
            return;
        }
        for(int col=0; col<n; col++){
            if(issafe(board, row, col, n)){
                board[row][col]='Q';
                helper(row+1, ans, board, n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        helper(0, ans, board, n);
        return ans;
    }
};