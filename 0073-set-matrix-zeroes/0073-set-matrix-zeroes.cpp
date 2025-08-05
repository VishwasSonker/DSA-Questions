class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        bool firstrow = false, firstcol = false;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j] == 0){
                    if(i==0) firstrow = true;
                    if(j==0) firstcol = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<rows; i++){
            for(int j=1; j<cols; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstrow){
            for(int i = 0; i<cols ; i++){
                matrix[0][i] = 0;
            }
        }
        if(firstcol){
            for(int j = 0; j<rows ; j++){
                matrix[j][0] = 0;
            }
        }
    }
};