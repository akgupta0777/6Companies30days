/*
Explanation:
This question is very similar to SDE sheet or Leetcode 493 Reverse Pairs question.
The problem statement says that we need two indices i,j such that 0<i<j<n-1 i.e i<j and should be in range.
So for getting guaranteed i<j we need to use Merge and Sort technique in which we divide and sort the array
into halves but we can intercept in middle of sorting and can count the pairs which satisfies the inequality.

Approach:
As we learnt in linear inequality in maths we can write an equation by reordering the elements from left 
to right side or vice-versa.
So lets look at the equation
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
we can also write the above equation as
nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff

As we can observe we need the subtractions of i and j pairs and compare them.
So now it reduces to Reverse Pairs question (https://leetcode.com/problems/reverse-pairs/) 
Let a[i] = nums1[i]-nums2[i]
then a[j] = nums1[j]-nums2[j]

So equation will be
a[i] <= a[j] + diff (i<j)

Algorithm:
Prepare a seperate array and store differences a[i] for each index i from 0 to n-1.
Apply recursive mergeSort technique dividing the subarrays into halves.
Before merging count the pairs in those two halves, Take i from 1st halve and j from another halve (i<j).
Count the pairs satisfy the conditions.
Finally sort the halves and merge them.
Return the count of pairs.
*/

class Solution {
public:
    long long merge(int low,int mid,int high,vector<int>& nums,int& diff){
        long long count=0;
        int l=low,r=mid+1;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]+diff){
                count+=(high-r+1);
                l++;
            }else{
                r++;
            }
        }
        sort(nums.begin()+low,nums.begin()+high+1);
        return count;
    }

    long long mergeSort(int low,int high,vector<int>& nums,int& diff){
        if(low>=high) return 0;
        long long pairs=0;
        int mid = (low+high)/2;
        pairs+=mergeSort(low,mid,nums,diff);
        pairs+=mergeSort(mid+1,high,nums,diff);
        pairs+=merge(low,mid,high,nums,diff);
        return pairs;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> nums(n);
        for(int i=0;i<n;++i){
            nums[i] = nums1[i]-nums2[i];
        }
        return mergeSort(0,n-1,nums,diff);
    }
};