class Solution {
public:

    bool helper(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &dp){
        if(k==s3.length() &&i==s1.length() && j==s2.length())  // if we reached to end of String that means we didn't find any discrepencies, Hence the obtained string is interleaving
            return true;
        if(i<s1.length() && j<s2.length() && dp[i][j]!=-1) 
            return dp[i][j]; // if we have already solved for s1[i] and s2[j] use the memoized result
        bool ans=false;
        if(i<s1.length() && s1[i]==s3[k] && j<s2.length() && s2[j]==s3[k]) // if both s1[i] and s2[j] are equal to s3[k], here there are 2 possibilities, either we go with s1's i'th char or s2's j'th char
            ans = helper(s1,s2, s3, i+1, j, k+1, dp) || helper(s1,s2, s3, i, j+1, k+1, dp);
        else if(j<s2.length() && s2[j]==s3[k])
            ans = helper(s1,s2, s3, i, j+1, k+1, dp);// if s2[j] is equal to s3[k], then we solve for j+1th char of s2 and k+1th char s3
        else if(i<s1.length() && s1[i]==s3[k])// if s1[i] is equal to s3[k], then we solve for i+1th char of s1 and k+1th char s3
            ans = helper(s1,s2, s3, i+1, j, k+1, dp);
        return dp[i][j] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1=="")  return s2==s3;
        if(s2=="")  return s1==s3;
        if(s1.length()+s2.length()!=s3.length())    return false;
        vector<vector<int>> dp(102,vector<int>(102,-1));
        return helper(s1,s2,s3,0,0,0, dp);
    }
};