/*
Explanation:
We are basically checking if a word can be formed as a subsequence of the original word. If yes then we
increment count and finally return the count.

How we are checking its a subsequence ?
We are storing all the indices of a character inside a vector and taking the character from the word and
checking if we ever get too far in terms of index if we get we know we cannot make the word and we break out
otherwise we take the current index and store it for next character and so on.
*/

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