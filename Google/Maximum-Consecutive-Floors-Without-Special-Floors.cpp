class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        sort(special.begin(),special.end());
        int result = max(special[0]-bottom,top-special[special.size()-1]),diff;
        for(int i=1;i<special.size();++i){
            diff = special[i]-special[i-1];
            result=max(result,(diff>1)?(diff-1):0);
        }
        return result;
    }
};