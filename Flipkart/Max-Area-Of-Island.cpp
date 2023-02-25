class Solution {
public:
    
    vector<int> parent,ranks,sizes;
    
    void makeSet(int n){
        for(int i=0;i<n;++i){
            parent[i] = i;
        }
    }
    
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        
        return parent[node] = findParent(parent[node]);
    }
    
    void Union(int a,int b){
        a = findParent(a);
        b = findParent(b);
        
        if(a!=b){
            if(ranks[a] < ranks[b]){
                parent[a] = b;
                ranks[b]+=ranks[a];
                sizes[b]+=sizes[a];
            }else if(ranks[a] > ranks[b]){
                parent[b] = a;
                ranks[a]+=ranks[b];
                sizes[a]+=sizes[b];
            }else{
                parent[a] = b;
                ranks[b]++;
                sizes[b]+=sizes[a];
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        parent = vector<int>(r*c+1,0);
        ranks = sizes = vector<int>(r*c+1,1);
        makeSet(r*c+1);
        
        bool landFound = false;
        
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(grid[i][j] == 1){
                    landFound = true;
                    if(i-1>=0 and grid[i-1][j])
                        Union((i-1)*c+j,c*i+j);
                    
                    if(i+1<r and grid[i+1][j])
                        Union((i+1)*c+j,c*i+j);
                    
                    if(j-1>=0 and grid[i][j-1])
                        Union(i*c+j-1,c*i+j);
                    
                    if(j+1<c and grid[i][j+1])
                        Union(i*c+j+1,c*i+j);
                }
            }
        }
        
        if(!landFound)
            return 0;
        
        int maxArea;
        
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j)
                if(grid[i][j]){
                    int par = findParent(c*i+j);
                    maxArea = max(maxArea,sizes[par]);        
                }
        }
        
        return maxArea;
    }
};

// r-1*c+c 