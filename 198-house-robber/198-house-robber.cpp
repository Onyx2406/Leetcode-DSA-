class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector dp (nums.size(), 0);
        
        for(int i=0;i<nums.size();i++)
        {
            if(i == 0)  {dp[i] = nums[i];}
            else if(i == 1) {dp[i] = max(dp[i-1],nums[i]);}
            else    {
                dp[i] = max(nums[i] + dp[i-2] , dp[i-1]);
            }
        }
        return dp[nums.size()-1];
//         int sum1=0,sum2=0;
        
//         for(int i=0;i<nums.size();i+=2)
//         {
//             sum1+=nums[i];
//         }
//         for(int i=1;i<nums.size();i+=2)
//         {
//             sum2+=nums[i];
//         }
//         return max(sum1,sum2);
        
    }
};