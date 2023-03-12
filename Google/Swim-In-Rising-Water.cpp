class Solution {
public:
    
    vector<int> parent,ranks;
    
    void makeSet(int n){
        for(int i=1;i<n;++i){
            parent[i] = i;
        }
    }
    
    int findParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void Union(int a,int b){
        a = findParent(a);
        b = findParent(b);
        
        if(a!=b){
            if(ranks[a]<ranks[b]){
                parent[a] = b;
                ranks[b]+=ranks[a];
            }else if(ranks[b]<ranks[a]){
                parent[b] = a;
                ranks[a]+=ranks[b];
            }else{
                parent[a] = b;
                ranks[b]++;
            }
        }
    }
    
    bool isConnected(int a,int b){
        return findParent(a) == findParent(b);
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        parent = vector<int>(n*n,0);
        ranks = vector<int>(n*n,1);
        unordered_map<int,pair<int,int>> waterLevelPos;
        makeSet(n*n);
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                waterLevelPos[grid[i][j]] = {i,j};
            }
        }
        
        int r,c;
        int minRequiredTime = max({2*(n-1),grid[0][0],grid[n-1][n-1]});
            
        for(int time = 0;time<=(n*n)-1;++time){
            r = waterLevelPos[time].first;
            c = waterLevelPos[time].second;
            
            if(r-1>=0 && grid[r-1][c]<time){
                Union(n*(r-1)+c,n*r+c);
            }
            if(r+1<n && grid[r+1][c]<time){
                Union(n*(r+1)+c,n*r+c);
            }
            if(c-1>=0 && grid[r][c-1]<time){
                Union(n*r+c-1,n*r+c);
            }
            if(c+1<n && grid[r][c+1]<time){
                Union(n*r+c+1,n*r+c);
            }
            
            if(time>=minRequiredTime && isConnected(0,n*(n-1)+n-1))
                return time;
        }
        
        return n*n-1;
    }
};