class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        unordered_set<string> echo;
        for(int len=1;len<=n/2;++len){
            for(int left=0,right=len,count=0;left<n-len;++left,++right){
                if(text[left]==text[right]){
                    count++;
                }else
                    count = 0;
                if(count == len){
                    echo.insert(text.substr(left,right-left));
                    count--;
                }
            }
        }
        return echo.size();
    }
};