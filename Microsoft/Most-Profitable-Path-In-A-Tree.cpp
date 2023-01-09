/*
Explanation
We used 2 DFS here to get maximum income. One DFS is for getting the distances from root to all other nodes
so that we can follow a path from bob's node to root and also follow the same path for alice so that we 
can take advantage of bob's half amount or bob's open gate.Second DFS is for tracing the path to leaf which
gives maximum income.

Approach:
First calculate all the distance from root to every other node along with thier previous node from root.
The point of meeting of alice and bob will be at the middle of path so when depth and distance from bob
becomes equal then you have to half the amount.Finally we run second DFS to get maximum income as 
amounts are reduced and half accordingly.

Algorithm:
Run a DFS for getting distance from root and thier previous nodes along the way.
Make a pointer for bob node.
Run loop until you get bob pointer to root node.
On the way we are reducing amounts on basis of distance and depth accordingly.
After the amounts are reduced Run a second DFS to get maximum income from root node.
Finally return the maximum income.
*/

class Solution {
public:
    void getDistFromRoot(int node,int parent,int distance,vector<vector<int>>& adj,vector<int>& dist,vector<int>& previousNodes){
        dist[node]=distance;
        previousNodes[node]=parent;
        for(auto child : adj[node]){
            if(child==parent) continue;
            getDistFromRoot(child,node,distance+1,adj,dist,previousNodes);
        }
    }

    int getIncome(int node,int parent,vector<int>& amount,vector<vector<int>>& adj){
        int result=INT_MIN;
        for(auto child:adj[node]){
            if(child!=parent){
                result = max(result,getIncome(child,node,amount,adj)+amount[node]);
            }
        }
        if(result==INT_MIN) return amount[node];
        return result;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        vector<int> distFromRoot(n);
        vector<int> previousNodes(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        getDistFromRoot(0,-1,0,adj,distFromRoot,previousNodes);
        int tempBob = bob;
        int currentDist=0;
        while(tempBob!=0){
            if(distFromRoot[tempBob]==currentDist){
                amount[tempBob]/=2;
            }else if(distFromRoot[tempBob]>currentDist){
                amount[tempBob]=0;
            }
            currentDist++;
            tempBob = previousNodes[tempBob];
        }
        return getIncome(0,-1,amount,adj);
    }
};

/*
Explanation
Here we tried to optimize with 1 DFS only instead of 2. Basically we are merging two operations of DFS into
one.

Approach:
With single DFS we are calculating max Income until we reach bob node. Once we reach bob node we calculate 
distance from Bob node to other nodes and comparing with depth on the way to reduce amounts accordingly.

*/

class Solution {
public:
    vector<int> distFromBob;
    
    int getIncome(int node,int parent,int depth,vector<int>& amount,vector<vector<int>>& adj,int bob){
        int result = INT_MIN;
        int value=0;
        if(node == bob) distFromBob[node]=0;
        else distFromBob[node]=amount.size();
        for(auto child:adj[node]){
            if(child==parent) continue;
            result = max(result,getIncome(child,node,depth+1,amount,adj,bob));
            distFromBob[node]=min(distFromBob[node],distFromBob[child]+1);
        }
        if(distFromBob[node]>depth) value+=amount[node];
        else if(distFromBob[node]==depth) value+=amount[node]/2;
        if(result==INT_MIN) return value;
        return value+result;
    } 
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        distFromBob.resize(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return getIncome(0,-1,0,amount,adj,bob);
    }
};