/*
Explanation:
The solution to the problem is really simple we just need the project with maximum profit and minimum
capital required. We can maintain a vector of profit capital pairs and then sort them based on capitals
in ascending order. This will guarantee us to get lowest capital first.
Now for getting maximum profit we will use a priority queue or maxHeap and store projects based on available
capital and get the maximum profit project. We will repeat this process until either we run out of projects
or We don't have enough capital to put in our priority queue.

Time Complexity - O(NLogN)
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> profitCapital;
        int n = capital.size();
        for(int i=0;i<n;++i){
            profitCapital.push_back({profits[i],capital[i]});
        }
        sort(profitCapital.begin(),profitCapital.end(),[&](auto& v1,auto& v2){
            return v1.second<v2.second;
        });
        priority_queue<pair<int,int>> pq;
        int i=0;
        while(k--){
            for(i;i<n;++i){
                if(profitCapital[i].second<=w){
                    pq.push(profitCapital[i]);
                }else break;
            }
                if(pq.empty()){
                    break;
                }
                w+=pq.top().first;
                pq.pop();
        }
        return w;
    }
};