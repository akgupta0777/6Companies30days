class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long int maxMinProduct = -1;
        const int MOD = 1e9+7;
        int n = nums.size();
        vector<long long int> prefix(n,0),prevSmaller(n,-1),nextSmaller(n,n);
        stack<int> s;
        prefix[0] = nums[0];
        for(int i=0;i<n;++i){
            if(i>0){
                prefix[i] = prefix[i-1]+nums[i];
            }
            while(!s.empty() && nums[s.top()]>=nums[i]) s.pop();
            if(!s.empty()){
                prevSmaller[i] = s.top();
            }
            // cout<<prevSmaller[i]<<" ";
            s.push(i);
        }
        // cout<<"\n";
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;--i){
            while(!s.empty() && nums[s.top()]>=nums[i]) s.pop();
            if(!s.empty()){
                nextSmaller[i] = s.top();
            }
            // cout<<nextSmaller[i]<<" ";
            s.push(i);
        }
        // cout<<"\n";
        for(int i=0;i<n;++i){
            int prev = prevSmaller[i]+1;
            int next = nextSmaller[i]-1;
            long long int sum = (prefix[next]-(prev==0?0:prefix[prev-1]));
            maxMinProduct = max(maxMinProduct,(sum*nums[i]));
        }
        return maxMinProduct%MOD;
    }
};