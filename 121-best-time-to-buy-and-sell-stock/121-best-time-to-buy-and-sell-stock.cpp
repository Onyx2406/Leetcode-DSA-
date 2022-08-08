class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int max=0;
        
        int n = prices.size();
        
        for(int i=0;i<n;i++)
        {
            if(prices[i] < minprice)
            {
                minprice = prices[i];
            }
            else if(prices[i] - minprice > max)
            {
                max = prices[i] - minprice;
            }
        }
        return max;
    }
};