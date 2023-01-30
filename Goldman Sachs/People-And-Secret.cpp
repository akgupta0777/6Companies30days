class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(forget,0);
        dp[0]=1;
        long share = 0,MOD=1e9+7;
        for(int day=1;day<n;++day){
            dp[day%forget] = share = (share + dp[(day-delay+forget)%forget] - dp[day%forget] + MOD)%MOD;
        }
        return accumulate(dp.begin(),dp.end(),0LL)%MOD;
    }
};