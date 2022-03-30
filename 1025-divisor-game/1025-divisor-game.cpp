class Solution {
public:
    bool divisorGame(int n) {
        if(n == 1)  return false;
        
        vector<int> dp(n+1,0);
        
        for(int j=2;j<=n;j++)
        {
            for(int i=1;i<=sqrt(j);i++)
            {
                if(j%i == 0 && dp[j-i] == 0)
                {
                    dp[j] = 1;
                }
            }
        }
        if(dp[n] == 1)  return true;
        return false;
        
    }
};