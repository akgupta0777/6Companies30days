class Solution {
public:
    void buildGraph(vector<vector<pair<int,int>>>& graph,vector<vector<int>>& flights){
        for(auto flight : flights){
            graph[flight[0]].push_back({flight[1],flight[2]});
        }
    }

    int getCheapestFlight(int src,int dest,int stops,int& k,vector<vector<pair<int,int>>>& graph,vector<vector<int>>& cache){
        if(stops>k+1) return 1e6;

        if(src == dest){
            if(stops<=k+1){
                return 0;
            }
            // return 1e6;
        }

        if(cache[src][stops]!=-1) return cache[src][stops];

        int cheapestPrice = 1e6;
        for(auto [flight,fare]:graph[src]){
            int price = fare+getCheapestFlight(flight,dest,stops+1,k,graph,cache);
            cheapestPrice = min(price,cheapestPrice);
        }
        return cache[src][stops] = cheapestPrice;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int,int>>> graph(n);
        buildGraph(graph,flights);
        vector<vector<int>> cache(n,vector<int>(k+2,-1));
        return getCheapestFlight(src,dest,0,k,graph,cache)==1e6?-1:cache[src][0];
    }
};