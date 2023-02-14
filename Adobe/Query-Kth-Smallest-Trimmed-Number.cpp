class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans;
        vector<pair<string,int>> vec;
        int k,trim;
        
        for(auto q : queries){
            vec.clear();
            k = q[0];
            trim = q[1];
            for(int i=0;i<n;++i){
                vec.push_back({nums[i].substr(nums[i].size()-trim),i});
            }
            sort(vec.begin(),vec.end());
            ans.push_back(vec[k-1].second);
        }
        return ans;
    }
};