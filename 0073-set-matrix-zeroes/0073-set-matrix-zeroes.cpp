class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroes;
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == 0){
                    zeroes.push_back({i, j});
                }
            }
        }

        for(int i=0; i<zeroes.size(); i++){
            int k = zeroes[i].first + 1;
            int l = zeroes[i].second + 1;
            while(k<rows){
                matrix[k][zeroes[i].second] = 0;
                k++;
            }
            while(l<cols){
                matrix[zeroes[i].first][l] = 0;
                l++;
            }
            int a = zeroes[i].first - 1;
            int b = zeroes[i].second - 1;
            while(a>=0){
                matrix[a][zeroes[i].second] = 0;
                a--;
            }
            while(b>=0){
                matrix[zeroes[i].first][b] = 0;
                b--;
            }
        }
    }
};