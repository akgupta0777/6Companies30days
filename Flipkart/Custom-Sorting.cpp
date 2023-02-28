class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> priority;
        int val=0;
        for(char c : order){
            priority[c]=val++;
        }
        sort(s.begin(),s.end(),[&](char a,char b){
            return priority[a]<priority[b];
        });
        return s;
    }
};