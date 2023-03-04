class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> distinct;
        int n = nums.size();
        for(int i=0;i<n;++i){
            vector<int> vec;
            int count = 0;
            for(int j=i;j<n;++j){
                vec.push_back(nums[j]);
                if(nums[j]%p==0) ++count;
                if(count>k) break;
                distinct.insert(vec);
            }
        }
        return distinct.size();
    }
};