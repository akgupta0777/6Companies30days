/*
Explanation:
If we need to divide the nums into k equal sum subsets then total sum should be divisible by K and number
of elements in nums should be greater than K. We will use bit manipulation power set technique along with
dynamic programming to cache the results.
We will create mask of the power set to generate all combinations of sums and we will store the remainder
by required Sum. If the remainder of the mask where all the elements are used is 0 then it is possible to 
split into K equal sum subsets.
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k || n<k) return false;
        int requiredSum = sum/k;
        vector<int> cache(((1<<n)),-1);
        cache[0] = 0;
        for(int mask=0;mask<(1<<n);++mask){
            if(cache[mask]==-1){
                continue;
            }
            for(int i=0;i<n;++i){
                if(!(mask&(1<<i)) && cache[mask]+nums[i]<=requiredSum){
                    cache[mask|(1<<i)] = (cache[mask]+nums[i])%requiredSum;
                }
            }
        }
        return cache[(1<<n)-1] == 0;
    }
};