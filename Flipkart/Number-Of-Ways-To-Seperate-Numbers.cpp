class Solution {
public:
    int numberOfCombinations(string num) {
        if(num[0]=='0') return 0;
        int n = num.size();
        int MOD = 1e9+7;
        int count[n][n],dp[n][n];
        memset(count,0,sizeof(count));
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;--i){
            if(num[i]=='0') continue;
            for(int j=n-1,sum=0;j>=i;--j){
                if(j==n-1) count[i][j] = 1;
                else{
                    int len = j-i+1,begin=j+1,end=begin+len;
                    int cnt=0;
                    if(end<=n && memcmp(&num[i],&num[begin],len)<=0){
                        cnt = (cnt+count[begin][end-1])%MOD;
                    }
                    if(end<n){
                        cnt = (cnt+dp[begin][end])%MOD;
                    }
                    count[i][j]=cnt; 
                }
                dp[i][j] = sum = (sum+count[i][j])%MOD;
            }
        }
        return dp[0][0];
    }
};