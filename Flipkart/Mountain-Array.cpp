/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray& mountainArr,int& target,int low,int high,bool asc=true){
        while(low<=high){
            int mid = (low+high)>>1;
            int val = mountainArr.get(mid);
            if(val == target) return mid;
            else if(asc == val < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = 0,high = mountainArr.length()-1;
        while(peak<high){
            int mid = (peak+high)>>1;
            int val = mountainArr.get(mid);
            if(val > mountainArr.get(mid+1)){
                high = mid;
            }else{
                peak = mid+1;
            }
        }
        int index = binarySearch(mountainArr,target,0,peak);
        return index!=-1?index:binarySearch(mountainArr,target,peak,mountainArr.length()-1,false);
    }

};