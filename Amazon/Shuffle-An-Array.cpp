class Solution {
private:
    vector<int> original;
public:
    Solution(vector<int>& nums) {
        this->original = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int> perm = original;
        for(int i=0;i<perm.size();++i){
            int randomPos = rand()%(perm.size()-i);
            swap(perm[i+randomPos],perm[i]);
        }
        return perm;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */