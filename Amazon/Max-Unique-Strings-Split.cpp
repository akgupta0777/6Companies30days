class Solution {
public:
    unordered_set<string> unique;
    int maxUniqueSplit(string s,int index = 0) {
        int n = s.size();
        if(index>=n) return 0;
        if(n==1) return n;
        int result = -1;
        for(int i=1;i<=n-index;++i){
            string sub = s.substr(index,i);
            if(!unique.count(sub)){
                unique.insert(sub);
                int nextResult = maxUniqueSplit(s,index+i);
                if(nextResult!=-1) result = max(result,1+nextResult);
                unique.erase(sub); 
            }
        }
        return result;
    }
};