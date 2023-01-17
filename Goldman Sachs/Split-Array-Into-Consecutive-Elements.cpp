class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> count,ending;
        // Counting all numbers
        for(int num:nums){
            count[num]++;
        }

        for(int num:nums){
            // Skipping already taken numbers in subsequence.
            if(!count[num]) continue;
            // Reducing count because we took it.
            count[num]--;
            // Checking if the current number can be appended to a already created subsequence
            if(ending[num-1]>0){
                ending[num-1]--;
                ending[num]++;
            }// If not then check can we make a new subsequence of length atleast 3.
            else if(count[num+1] && count[num+2]){
                count[num+1]--;
                count[num+2]--;
                ending[num+2]++;
            }// If still no, We can't make a subsequence and return false.
            else{
                return false;
            }
        }

        // If we splitted whole nums into subsequence return true
        return true;
    }
};