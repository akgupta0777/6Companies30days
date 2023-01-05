/*
Author: Abhay Gupta(akgupta0777)
Explanation:
Approach : Recursion with backtracking.
Problem : The problem states we need all the unique combination of k numbered sequence that adds to n
with each number used atmost once.
We can observe that a number can be added or not added to the sequence, These are the only options we have
i.e To choose a number or to leave the number.
So we explore both options of choosing and leaving the number and whenever we found a valid combination
we will simply add it to the result combinations which needs to be returned.

Algorithm:
We run our recursive function to start the process.
We start from the value either previous where combination ends or default 1 till 9 to explore all possibilties.
we try to add the value in combination and look for remaining values for the combination.
base case : when our n and k becomes 0 it means we found a valid combination so we push it in combinations.
after the recursive calls are done we return the combinations.
*/

class Solution {
public:
    void solve(int k,int n,vector<vector<int>>& combinations,vector<int>& combination){
        if(n<0 || k<0) return ;
        if(k==0 && n==0){
            combinations.push_back(combination);
            return ;
        }
        int start = 1;
        if(combination.size())
            start = combination.back();
        for(int i=start;i<=9;++i){
            if(n<i) break;
            combination.push_back(i);
            solve(k-1,n-i,combinations,combination);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> combination;
        solve(k,n,combinations,combination);
        return combinations;
    }
};