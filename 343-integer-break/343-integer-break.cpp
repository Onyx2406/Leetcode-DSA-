class Solution {
public:
    int integerBreak(int n) {
        if(n<4) return n-1; 
        vector<long>dp(n+2,0);

        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4; i<=n+1; i++){
            dp[i]= max(dp[i/2]*dp[i-i/2], max(dp[i/2+1]*dp[i-(i/2+1)], dp[i/2-1]*dp[i-(i/2-1)] ));
        }
        return dp[n];
    }
};