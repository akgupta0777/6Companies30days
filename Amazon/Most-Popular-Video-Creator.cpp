class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        priority_queue<long long int> popular;
        int n = ids.size();
        map<string,map<long long int,set<string>>> idSet;
        map<string,long long int> viewCnt;
        for(int i=0;i<n;++i){
            viewCnt[creators[i]]+=views[i];
            idSet[creators[i]][views[i]].insert(ids[i]);
        }
        for(auto x : viewCnt){
            popular.push(x.second);
        }
        long long int highest = popular.top();
        popular.pop();
        vector<vector<string>> result;
        for(auto x : viewCnt){
            if(x.second == highest){
                auto idMap = idSet[x.first].rbegin()->second;
                // cout<<(*idMap.begin())<<"\n";
                result.push_back({x.first,(*idMap.begin())});
            }
        }
        // s//ort(result.begin(),result.end());
        return result;
    }
};