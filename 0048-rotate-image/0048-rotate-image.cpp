class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i = 0, j = rows-1;
        while(i<j){
            for(int k=0; k<cols; k++){
                swap(matrix[i][k], matrix[j][k]);
            }
            i++;
            j--;
        }
        for(int i = 0; i<rows; i++){
            for(int j = 0 ; j < cols ; j++){
                if(i<j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    }
};