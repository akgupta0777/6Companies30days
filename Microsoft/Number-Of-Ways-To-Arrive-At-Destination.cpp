/*
Explanation
The problem statement says to find number of ways we can reach from 0 to n-1 node in a graph with shortest
time.

Observation:
Whenever we see shortest path that originates from single source to destination. We always come up with 
Dijkstra algorithm.With Dijkstra algorithm we can find the shortest path from a single source to every other
vertex in ElogV time.

Approach:
While assigning shortest time to shortest path vertex from source we can also update ways if we maintain
ways along with dijkstra algorithm. If there are two different path from src to a vertex then we add both
ways of those paths vertex.Finally when dijkstra is over then we have number of ways with shortest time
for each vertex from source. We will return the ways of n-1 node.
*/

class Solution {
public:
    const int MOD=1e9+7;
    int dijkstra(int src,int n,vector<vector<pair<long long,long long>>>& adj){
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long ,long long>>> pq;
        vector<long long> dist(n,LONG_MAX);
        vector<long long> ways(n,0);
        dist[src]=0;
        ways[src]=1;
        pq.push({0,src});
        while(!pq.empty()){
            auto [d,curr] = pq.top();pq.pop();
            if(d>dist[curr]) continue;
            for(auto [child,time] : adj[curr]){
                if(dist[child]>d+time){
                    dist[child]=d+time;
                    ways[child]=ways[curr];
                    pq.push({dist[child],child});
                }else if(dist[child]==d+time){
                    ways[child] = (ways[child]+ways[curr])%MOD;
                }
            } 
        }
        return ways[n-1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> adj(n);
        long long from,to,time;
        for(auto road : roads){
            from=road[0],to=road[1],time=road[2];
            adj[from].push_back({to,time});
            adj[to].push_back({from,time});
        }
        return dijkstra(0,n,adj);
    }
};