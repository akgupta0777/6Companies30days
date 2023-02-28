class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> fruitMap;
        int maxFruits=0;
        int start=0,end;
        for(end=0;end<fruits.size();++end){
            fruitMap[fruits[end]]++;
            if(fruitMap.size()>2){
                maxFruits=max(maxFruits,end-start);
                fruitMap[fruits[start]]--;
                if(fruitMap[fruits[start]]==0){
                    fruitMap.erase(fruits[start]);
                }
                start++;
            }
        }
        maxFruits = max(maxFruits,end-start);
        return maxFruits;
    }
};