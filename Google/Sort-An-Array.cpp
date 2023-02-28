class Solution {
public:
    void merge(vector<int>& nums,int low,int mid,int high){
        if(low>=high) return ;
        int index = 0;
        int l=low,r=mid+1;
        vector<int> sorted(high-low+1,0);
        while(l<=mid && r<=high){
            sorted[index++] = nums[l]<nums[r]?nums[l++]:nums[r++];
        }
        while(l<=mid){
            sorted[index++] = nums[l++];
        }
        while(r<=high){
            sorted[index++] = nums[r++];
        }
        for(int k=0;k<sorted.size();++k){
            nums[low+k] = sorted[k];
        }
    }

    void mergeSort(vector<int>& nums,int low,int high){
        if(low>=high) return;
        int mid = (low+high)>>1;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};