class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> alpha(26);
        int n = s.size();
        
        int ans = 0;

        for(int i=0;i<n;++i){
            alpha[s[i]-'a'].push_back(i);
        }
        
        for(auto word : words){
            int x = -1;
            bool isFound = true;
            
            for(char c: word){
                auto next = upper_bound(alpha[c-'a'].begin(),alpha[c-'a'].end(),x);
                if(next == alpha[c-'a'].end()){
                    isFound = false;
                    break;
                }
                x = *next;
            }
            if(isFound){
                ans++;
            }
        }
        return ans;
    }
};