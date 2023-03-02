class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    void bfs(vector<vector<int>>& grid,int r,int c){
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c]=1;
        while(!q.empty()){
            pair<int,int> current = q.front();
            q.pop();
            for(int i=0;i<4;++i){
                int newX=current.first+dirs[i][0];
                int newY=current.second+dirs[i][1];
                if(newX<0 || newY<0 || newX>=grid.size() || newY>=grid[0].size() || grid[newX][newY]==1)
                continue;
                q.push({newX,newY});
                grid[newX][newY]=1;
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if((i*j==0 || i==rows-1 || j==cols-1)&&grid[i][j]==0){
                    bfs(grid,i,j);
                }
            }
        }
        int islands=0;
        for(int i=1;i<rows-1;++i){
            for(int j=1;j<cols-1;++j){
                if(grid[i][j]==0){
                    bfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};