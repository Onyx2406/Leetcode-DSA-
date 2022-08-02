class Solution {
public:
int dp[5001][3];

int maxProfit(vector<int>& prices) {
    memset(dp, -1, sizeof(dp));
    
    return solve(prices, 0, 1); // starting from vary first day, and enable to buy stock, so pre =  1;
}

int solve(vector<int>& prices, int pos, int pre)
{
    if(pos == prices.size())  // base case, traversed full array
        return 0;
    
    if(dp[pos][pre]!=-1)
        return dp[pos][pre];
    
	// pre = previous operation
	// pre = 2; we have bought stock already, now we can sell it;
	//pre = 1; we don't have any stock, but now in this position we can buy stock 
	//pre = 0; we don't have any stock, we have sold our stock just previous day, so in this position we can't buy any stock;
	
    int res = 0;
    if(pre == 0)   // yet not ready to buy 
    {
			res = max(res, solve(prices, pos + 1, 1));  // enabling pre = 1, so next day can buy stock
    }
    else if(pre == 1) // ready to buy
    {
        res = max(res, solve(prices, pos + 1, 1));   //don't buy, leave it for next day
        
        res = max(res, solve(prices, pos + 1, 2) - prices[pos]); //buy stock in current day, enabling pre=2, so from next day stock can be sold
    }
    else if(pre == 2) //ready to sell stock
    {
        res = max(res, solve(prices, pos + 1, 2)); //don't sell, leave it for next day
        
        res = max(res, solve(prices, pos + 1, 0) + prices[pos]);  //sell stock in current day, making pre = 0 thus next day will not enable to buy any stock
    }
    
    return dp[pos][pre] = res;  // storing the best result and returning
}
};