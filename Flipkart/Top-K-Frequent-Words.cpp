class comp {
  public:
    bool operator() (const pair<int,string> &p1, const pair<int,string> &p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      
      return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result(k);
        unordered_map<string,int> freqMap;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        for(string word : words){
            freqMap[word]++;
        }

        for(auto [word,freq] : freqMap){
            pq.push({freq,word});
            if(pq.size()>k) pq.pop();
        }
        
        while(k--){
            result[k] = pq.top().second;
            pq.pop();
        }
        return result;
    }
};