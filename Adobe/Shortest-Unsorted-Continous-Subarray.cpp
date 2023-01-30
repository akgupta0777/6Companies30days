/*
Explanation:
For making an array sorted you need to place the unsorted values at thier correct positions.
How to identify such values that are not in correct place ? We can identify by checking if the current 
element we are at is lesser than the maximum value on its left and also by checking if the current element
we are at is larger than the minimum value on its right.

Example
[2,6,4,8,10,9,15]

2,  maxValue=2          
6,  maxValue=6
4,  4<maxValue (wrong place)
8,  maxValue=8   
10, maxValue=10   
9,  9<maxValue (Wrong place)  This is end of our unsorted continuous sub-array.      
15  maxValue=15

Similarly

15,  minValue=15          
9,   minValue=9
10,  10>minValue (wrong place)
8,   minValue=8   
4,   minValue=4   
6,   6>minValue (Wrong place)  This is start of our unsorted continuous sub-array.      
2    minValue=2

So result will be end-start+1
By default we initialize start=-1 and end=-2 so that if there is a already sorted array then 
end-start+1 will be 0 in that case.

Algorithm:
Initialize start=-1 and end=-2.
Run a loop to process all the elements inside array.
Update minValue and maxValue at every step.
If element is < maxValue and element > minValue mark those positions for start and end of subarrays.
Return the length for those subarrays with end-start+1.

*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start=-1,end=-2;
        int n = nums.size();
        int maxValue=nums[0],minValue=nums[n-1];
        for(int i=1;i<n;++i){
            maxValue=max(maxValue,nums[i]);
            if(nums[i]<maxValue) end=i;
            minValue=min(minValue,nums[n-1-i]);
            if(nums[n-1-i]>minValue) start=n-1-i;
        }
        return end-start+1;
    }
};