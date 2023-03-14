class TweetCounts {
private:
    unordered_map<string,vector<int>> tweetRecords;
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweetRecords[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> tweetsCount;
        int chunkSize = freq=="minute"?60:(freq=="hour"?3600:86400);
        for(int i=0;i<=(endTime-startTime)/chunkSize;++i){
            tweetsCount.push_back(0);
        }
        for(int time : tweetRecords[tweetName]){
            if(time>=startTime && time<=endTime){
                int index = (time-startTime)/chunkSize;
                tweetsCount[index]++;
            }
        }
        return tweetsCount;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */