class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto time : times){
            adj[time[0]-1].push_back({time[1]-1,time[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k-1});
        vector<int> distance(n,1e6);
        vector<int> visited(n,0);
        distance[k-1]=0;
        int delay = -1;
        while(!pq.empty()){
            int currentTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(visited[node]) continue;
            visited[node] = 1;
            for(auto child : adj[node]){
                if(distance[child.first]>distance[node]+child.second){
                    distance[child.first]=distance[node]+child.second;
                    pq.push({distance[node]+child.second,child.first});
                    // delay = max(delay,distance[child.first]);
                }
            }
        }
        delay = *max_element(distance.begin(),distance.end());
        if(delay == 1e6) return -1;
        return delay;
    }
};