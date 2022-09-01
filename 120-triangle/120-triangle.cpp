class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) { 
    int n = triangle.size();
    int m = triangle[0].size();
    int dp[n][n];
	
    for(int j = 0; j <n ;j++){
        dp[n-1][j]=triangle[n-1][j];
    }
    for(int i = n-2 ; i>=0 ;i--){
        for(int j = i ; j>=0 ;j--){
            int down = triangle[i][j]+dp[i+1][j];
            int dg = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,dg);
        }
    }
    return dp[0][0];
}
};