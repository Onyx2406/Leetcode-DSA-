class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1,vector<int> (matrix.size() +1 , 0));
        
        for(int row = matrix.size()-1;row>=0;row--)
        {
            for(int col = 0;col<matrix.size();col++)
            {
                if(col == 0)
                {
                    dp[row][col] = min(dp[row+1][col],dp[row+1][col+1])+matrix[row][col];
                }
                else if (col == matrix.size() - 1) {
                    dp[row][col] = min(dp[row + 1][col], dp[row + 1][col - 1]) +
                                   matrix[row][col];
                } else {
                    dp[row][col] =
                        min(dp[row + 1][col],
                            min(dp[row + 1][col + 1], dp[row + 1][col - 1])) +
                        matrix[row][col];
                }
            }
        }
        int minsum = INT_MAX;
        
        for(int startcol =0;startcol<matrix.size();startcol++)
        {
            minsum = min(minsum,dp[0][startcol]);
        }
        return minsum;
    }
};