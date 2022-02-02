class Solution {
public:
     vector<int> finalPrices(vector<int>& prices){

      stack<int> st;
      for(int i=prices.size()-1;i>=0;i--)
      {
        if(st.empty())
        {
          st.push(prices[i]);
        }
        else
        {
          while(!st.empty() && st.top()>prices[i]) st.pop();
          int curr=prices[i];
          if(!st.empty()) prices[i]-=st.top();
          st.push(curr);
        }
      }
      return prices;
    }
};