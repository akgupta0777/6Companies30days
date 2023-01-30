/*
Explanation:
We can use Longest Increasing Subsequence algorithm from Dynamic Programming and find the increasing 
subsequence and check if the size is greater than or equal to 3 and return true and false accordingly.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> subsequence;

        for(int num : nums){
            if(subsequence.empty() || subsequence.back()<num){
                subsequence.push_back(num);
            }else{
                auto it = lower_bound(subsequence.begin(),subsequence.end(),num);
                *it = num;
            }
        }
        return subsequence.size()>=3;
    }
};