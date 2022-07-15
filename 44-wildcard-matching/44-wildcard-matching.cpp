class Solution {
private:
    int solve(string &s,string &p,int n,int m,vector<vector<int>> &dp){
        // base case
        
        // Case 1 : if both string exhaust 
        if(n < 0 and m < 0){
            return true;
        }
        
        // case 2 : if pattern exhaust but string don't
        if(m < 0 and n >= 0){
            return false;
        }
        
        // case 3 : if pattern is left but string left 
        if(n < 0 and m >= 0){
            for(int i=0;i<=m;i++){
                if(p[i] != '*'){
                    return false;
                }
            }
            
            return true;
        }
        
        // Checking dp array
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        
        if(s[n] == p[m] or p[m] == '?'){
            dp[n][m] = solve(s,p,n-1,m-1,dp);
        }
        else if(p[m] == '*'){
            dp[n][m] = solve(s,p,n-1,m,dp) or solve(s,p,n,m-1,dp);
        }
        else{
            dp[n][m] = false;
        }
        
        
        return dp[n][m];
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,p,n-1,m-1,dp);
    }
};  