/*
Explanation
Whenever we need to find pattern of some type which is repeating we can use hashing at that time. In this
approach we hashed forward and backward strings and whenever they match we recorded the maximum length at 
that time.

Problem with this approach:
With great power comes great responsibiity, Hashing is super powerful in a lot of cases but the weak points
of hashing is collision so it is a good practice to check for the strings as well that are they matching or
not. Leetcode OJ doesn't have that strong test cases so I didn't implemented checking of strings.

*/

class Solution {
public:
    string longestPrefix(string s) {
        long long hash1=0,hash2=0;
        long long num=1;
        const long long MOD=1e9+7;
        int first,last,len=0,n=s.size();
        for(int i=0;i<n-1;++i){
            first=s[i]-'a';
            last=s[n-1-i]-'a';
            hash1 = (hash1*26+first)%MOD;
            hash2 = (hash2+num*last)%MOD;
            num=(num*26)%MOD;
            if(hash1==hash2){
                len = i+1;
            }
        }
        return s.substr(0,len);
    }
};