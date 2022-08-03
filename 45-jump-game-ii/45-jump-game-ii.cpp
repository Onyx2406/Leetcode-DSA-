class Solution {
public:
    //f(i) denotes minimum steps needed to go from i to last index (n-1)
    int f(int i, vector<int>& nums, int n, vector<int>& dp)
    {
        // base case is if we have already reached the last index
        // of the array or can reach beyond it then no jumps are needed
        if(i >= n-1) {
            return 0;
        }
        
        // if answer is already calculated return it
        if(dp[i]!=-1) 
            return dp[i];
        
        // loop over all possibilities of jumps from the current location
        // and choose the one which gives you the minimum jumps
        int ans = n+1;
        
        for(int j = i+1; j <= i+nums[i]; j++)
        {
            ans = min(ans, 1 + f(j, nums, n, dp));
        }
        
        return dp[i] = ans;
    }
    
    int jump(vector<int>& nums) {
        // Memoization
        // f(0) denotes minimum steps needed to go from 0th index to last index (n-1)
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return f(0, nums, n, dp);
        
        // Tabulation
        n = nums.size();
     
        
        // initialization
        dp[n-1] = 0;
        
        for(int i=n-2; i>=0; i--)
        {
            int ans = n+1;
            for(int j=i+1; j <= i+nums[i]; j++) 
            {
                int tempAns;
                j >= n-1 ? tempAns = 0 : tempAns = dp[j];
                ans = min(ans, 1 + tempAns);
            }
            dp[i] = ans;
        }
        
        return dp[0];
    }
};