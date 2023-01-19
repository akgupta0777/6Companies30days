/*
Explanation:
In this problem we are tracking the last position of the card since we need to calculate the distance 
between two same valued cards.If we found the last position of the card exist we minimize the distance
of the card using last position.
*/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> lastPos;
        int minCards = INT_MAX;
        for(int i=0;i<cards.size();++i){
            if(lastPos.count(cards[i])){
                minCards = min(minCards,i-lastPos[cards[i]]+1);
            }
            lastPos[cards[i]]=i;
        }
        return minCards==INT_MAX?-1:minCards;
    }
};