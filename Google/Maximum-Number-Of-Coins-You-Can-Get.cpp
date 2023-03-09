class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int pilesToPick = n/3;
        sort(piles.begin(),piles.end(),greater<int>());
        if(pilesToPick==1) return piles[1];
        long long int maxCoinSum = 0;
        int i=1;
        while(pilesToPick--){
            maxCoinSum+=piles[i];
            i+=2;
        }
        return maxCoinSum;
    }
};