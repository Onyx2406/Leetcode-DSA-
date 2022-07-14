class Solution {
public:
    int solve(int i, vector<int> &dp,vector<int> &nums){
	//if size is 0 it means no house to rob so profit=0
        if(i==0)
            return 0;
	//if size is 1 it means single house to rob
        if(i==1){
            return nums[0];
        }
	//if value is already calculated due to overlapping subproblem then return
        if(dp[i]!=-1)
            return dp[i];
	//There are only two cases: house robbed and house not robbed
	
	//if a house is robbed then adjancent house cannot be robbed so add the value of ith house robbed ie i-1 index and call recursion after skipping adjacent house
        int pick = solve(i-2,dp,nums)+nums[i-1];
	//if a house is not robbed then nothing to add in profit, call recursion in the rest of the house. no skipping required as the house is not robbed
        int notpick =solve(i-1,dp,nums);

	//choose the one with max profit
        return dp[i]= max(pick,notpick);
    }
    int rob(vector<int>& nums) {    
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(n,dp,nums);       
    }
};