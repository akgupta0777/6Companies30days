/*
Explanation:
The statement says we need to find pairs of numbers such that they follow one of the conditions:
lets say pair is (a,b) then a%b==0 or b%a==0.

Observations:
a%b==0 can happen if and only if a>=b.This gives us direction in thinking that the subsets are all in 
increasing fashion.
For example: [1,2,4,8] every number is increasing.
But the given array is not sorted so we need to sort it.Since it is also increasing we can apply 
LIS(Longest Increasing Subsequence) here as well.

Algorithm:
We start with index 1 till length of array to process all nums.We are starting from 1 because we want to 
form pairs so atleast 1 number should be there before.
As in LIS algorithm we run another loop to explore the points where our LIS can end and increment it.
We will also store the indices of the points where LIS ends so that we can put all elements of LIS in final vector.
Check if a%b==0 (a>=b) satisfies and increase length of LIS suitably.
Finally store all the LIS elements inside a vector and return the vector.
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = size(nums), max_i = 0;
        vector<int> dp(n, 1), pred(n, -1), ans;
        for(int i = 1; i < n; i++) {          
            for(int j = 0; j < i; j++)     
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j]+1)
                    dp[i] = dp[j]+1, pred[i] = j;
            if(dp[i] > dp[max_i]) max_i = i;
        }
		
        for(; max_i >= 0; max_i = pred[max_i]) 
            ans.push_back(nums[max_i]);
        return ans;
    }
};