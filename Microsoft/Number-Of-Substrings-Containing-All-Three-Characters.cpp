/*
Explanation:
We are storing last position of each character a,b,c so when we take minimum and valid index is minimum
then it means we have found a valid substring and all the indices before the index will also be valid

Example 
a  b c a b c
  |     |
  min(bca) = 1
It means bca is valid and all the substrings formed by before index 1 will also be valid 
so bca(1) + abca(1)(also valid) = 2 

So that's how algorithm works.
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastPos[3] = {-1,-1,-1};
        int n=s.size();
        int result=0;
        for(int i=0;i<n;++i){
            lastPos[s[i]-'a']=i;
            result+=1+min({lastPos[0],lastPos[1],lastPos[2]});
        }
        return result;
    }
};