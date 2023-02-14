class StockPrice {
public:
    map<int,int> timeStamps;
    multiset<int> prices;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(timeStamps.count(timestamp)){
            prices.erase(prices.find(timeStamps[timestamp]));
        }
        timeStamps[timestamp]=price;
        prices.insert(price);
    }
    
    int current() {
        return timeStamps.rbegin()->second;
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};
