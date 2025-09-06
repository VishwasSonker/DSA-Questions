class Solution {
public:

    bool issafe(vector<vector<char>>& board, int row, int col, char num){
        // row & col check
        for(int i=0; i<9; i++){
            if(board[row][i]==num) return false;
            if(board[i][col]==num) return false;
        }

        // 3x3 subgrid check
        int startRow = (row/3)*3;
        int startCol = (col/3)*3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[startRow+i][startCol+j] == num) return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col){
        if(row==9) return true;
        
        if(col==9) return helper(board, row+1, 0);
        
        if(board[row][col]!='.') return helper(board, row, col+1);

        for(int i=1; i<=9; i++){
            char c = char(i + '0');
            if(issafe(board, row, col, c)){
                board[row][col]=c;
                if(helper(board, row, col+1)) return true;
                board[row][col]='.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};