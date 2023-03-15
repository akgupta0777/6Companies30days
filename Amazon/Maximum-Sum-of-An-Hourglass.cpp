class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r=0;r<rows;++r){
            for(int c=1;c<cols;++c){
                grid[r][c] += grid[r][c-1];
            }
        }
        int maxHourGlassSum = -1;
        int sum = 0;
        for(int r=1;r<rows-1;++r){
            for(int c=1;c<cols-1;++c){
                sum = (grid[r-1][c+1]-(c-1==0?0:grid[r-1][c-2])) + (grid[r][c]-grid[r][c-1]) + (grid[r+1][c+1]-(c-1==0?0:grid[r+1][c-2]));
                maxHourGlassSum = max(maxHourGlassSum,sum); 
            }
        }
        return maxHourGlassSum;
    }
};