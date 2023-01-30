/*
Explanation:
DP Rolling Array problem. We make an array of size N(number of days) and each cell in dp array i.e 
dp[day] means that on this day people found a secret.
similarly dp[day-delay] means how many people found the secret delay days before
and dp[day-forget] means how many people found the secret forget days before.
share is number of people shared the secret.

Recurrence is dp[day] = share = (share + dp[day-delay] - dp[day-forget] + mod)%mod;

Why extra mod added ?
Because (a-b)%MOD = (a - b + MOD)%MOD

Can we optimize space ?
Yes, As we know people who share secrets will forget after forget days so we only need to use the cells
for forget days. Below is the optimized space code.

*/
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