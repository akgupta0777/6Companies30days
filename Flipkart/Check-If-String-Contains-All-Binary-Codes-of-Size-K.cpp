class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size()) return false;
        int value = 0,allOnes = (1<<k)-1;
        unordered_set<int> possibleValues;
        // cout<<value<<"\n";
        for(int i=0;i<s.size();++i){
            value = (value<<1)|(s[i]-'0');
            value = value&allOnes;
            if(i>=k-1){
                possibleValues.insert(value);
                if(possibleValues.size() == (1<<k)) return true;
            }
        }
        return false;
    }
};