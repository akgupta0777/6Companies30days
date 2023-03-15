
class Solution {
public:
    const int MOD = 1e9+7;
    vector<vector<int>> dp;
    
    int getWays(int startPos,int endPos,int k){
        
        if((k == 0) && (startPos == endPos)){
            // ans = (ans%MOD + 1)%MOD;
            return 1;
        }
        
        if(k <= 0)
            return 0;
        
        if(dp[startPos+1000][k] != -1) return dp[startPos+1000][k];

        int ans = getWays(startPos+1,endPos,k-1)%MOD;
        
        if((k-1) >= endPos-startPos+1){
            ans += getWays(startPos-1,endPos,k-1)%MOD;
        }
                
        dp[startPos+1000][k] = ans%MOD;
        return dp[startPos+1000][k];
        
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        dp.resize(3005,vector<int>(1005,-1));
        if(abs(startPos-endPos)>k) return 0;
        return getWays(startPos,endPos,k);
        
        
    }
};