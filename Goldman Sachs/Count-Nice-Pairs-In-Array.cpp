/*
Explanation:
nums[i]+rev(nums[j]) == nums[j]+rev(nums[i])
can turn into 
nums[i]-rev(nums[i]) == nums[j]-rev(nums[j])

So we just want to calculate number of pairs we can form by the difference between original and reverse
*/

class Solution {
public:
    int reverse(int n){
        int num=0;
        while(n){
            num=num*10+(n%10);
            n/=10;
        }
        return num;
    }
    int MOD = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count=0;
        for(int num : nums){
            count = (count+mp[num-reverse(num)]++)%MOD;
        }
        return count;
    }
};