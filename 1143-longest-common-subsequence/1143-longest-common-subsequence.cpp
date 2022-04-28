class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
    // tabulation
    int m = s.size();
    int n = t.size();
    if(m == 0 || n == 0) {
        return 0;
    }
    int** dp = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
    }
    dp[0][0] = 0;
    // filling first row with all 0s
    for(int j = 1; j <= n; j++) {
        dp[0][j] = 0;
    }
    // filling first col with all 0s
    for(int i = 1; i <= m; i++) {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            // most imp part
            if(s[m - i] == t[n - j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
        
    }
};