class Solution {
public:
    map<vector<int>,int> cache;
    int calculateSinglePrice(vector<int>& prices,vector<int>& needs){
        int price = 0;
        for(int i=0;i<prices.size();++i){
            price+=prices[i]*needs[i];
        }
        return price;
    }

    void removeOfferNeeds(vector<int>& offer,vector<int>& needs){
        for(int i=0;i<offer.size()-1;++i){
            needs[i]-=offer[i];
        }
    }

    bool isValid(vector<int>& needs){
        for(int i=0;i<needs.size();++i){
            if(needs[i]<0) return false;
        }
        return true;
    }

    void addOfferNeeds(vector<int>& offer,vector<int>& needs){
        for(int i=0;i<offer.size()-1;++i){
            needs[i]+=offer[i];
        }
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(cache.count(needs)) return cache[needs];
        int lowestPrice = calculateSinglePrice(price,needs);
        for(auto offer : special){
            removeOfferNeeds(offer,needs);
            if(isValid(needs)){
                int offerPrice = offer.back() + shoppingOffers(price,special,needs);
                lowestPrice = min(lowestPrice,offerPrice);
            }
            addOfferNeeds(offer,needs);
        }
        return cache[needs] = lowestPrice;
    }
};