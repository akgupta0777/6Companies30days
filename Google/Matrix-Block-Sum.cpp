class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> answer(rows,vector<int>(cols,0));
        vector<vector<int>> sum(rows+1,vector<int>(cols+1,0));

        for(int i=1;i<=rows;++i){
            for(int j=1;j<=cols;++j){
                sum[i][j] = mat[i-1][j-1] + sum[i-1][j] + sum[i][j-1] 
                - sum[i-1][j-1];
            }
        }

        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                int r1 = max(0,i-k)+1;
                int r2 = min(rows-1,i+k)+1;
                int c1 = max(0,j-k)+1;
                int c2 = min(cols-1,j+k)+1;     
                answer[i][j] = sum[r2][c2] - sum[r2][c1-1] - sum[r1-1][c2] + sum[r1-1][c1-1];
            }
        }
        return answer;
    }
};