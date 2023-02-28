/*
Explanation:
We don't know who is good person or who is bad person we need to explore every possibility of each person
either good or bad by assigning them. We can do it with backtracking but for efficient solution we used
bit mainpulation basically trying every configuration of people either good or bad remind us of bits if 
person is good we turn that bit on and if its bad we turn the bit off. We can use the fact that all the 
combination of a specific elements can be represented by bits by using power set in bit manipulation.
For learning about power set and subsequences read here https://www.geeksforgeeks.org/print-subsequences-string-iterative-method/

We will generate every configuration and check if the config is valid or not by checking if all good persons
are speaking truth or not.

Time Complexity - O((N^2)(2^N))
Space Complexity - O(1)
*/

class Solution {
public:
    bool isValid(int config,vector<vector<int>>& statements,int n){
        for(int i=0;i<n;++i){
            if(config&1<<(n-1-i)){
                for(int j=0;j<n;++j){
                    if(statements[i][j]!=2 && statements[i][j]!=bool(config&1<<(n-1-j)))
                        return false;
                }
            }
        }
        return true;
    }

    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int result=0;
        for(int config=0;config<(1<<n);++config){
            if(isValid(config,statements,n)){
                result = max(result,__builtin_popcount(config));
            }
        }
        return result;
    }
};