class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int smallest = INT_MAX,countOfNeg=0;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]<0) countOfNeg++;
                smallest = min(smallest,abs(matrix[i][j]));
                totalSum+=abs(matrix[i][j]);
            }
        }
        if(countOfNeg&1){
            return totalSum-(2*smallest);
        }
        return totalSum;
    }
};