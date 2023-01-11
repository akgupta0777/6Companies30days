/*
Explanation:
For every number in nums to divide every number of numsDivide we can easily tell by numbers that divide 
the gcd of the numsDivide. So we will sort the whole nums and find the smallest number in nums that divides
the gcd and return that index.
*/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int g = numsDivide[0];
        int n = nums.size();
        
        for(int i=1;i<numsDivide.size();++i){
            g = gcd(g,numsDivide[i]);
        }

        
        for(int i=0;i<n && nums[i]<=g;++i){
            if(g%nums[i] == 0)
                return i;
        }
        
        return -1;
    }
};