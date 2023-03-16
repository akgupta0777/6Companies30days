class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant,dire;
        int n = senate.size();
        for(int i=0;i<n;++i){
            senate[i]=='R'?radiant.push(i):dire.push(i);
        }
        while(!radiant.empty() && !dire.empty()){
            int radiantIndex=radiant.front();
            radiant.pop();
            int direIndex = dire.front();
            dire.pop();
            if(radiantIndex<direIndex){
                radiant.push(radiantIndex+n);
            }else{
                dire.push(direIndex+n);
            }
        }
        return radiant.empty()?"Dire":"Radiant";
    }
};