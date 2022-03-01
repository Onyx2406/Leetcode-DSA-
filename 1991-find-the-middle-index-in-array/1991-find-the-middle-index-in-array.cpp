class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum0=0,sum1=0;
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        vector<int> prefix(1000);
        prefix[0]=0,prefix[1]=nums[0];
        
        for(int i=2;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                prefix[i]+=nums[j];
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=0;
            if(i == nums.size() - 1)
            {
                if(prefix[i] == 0)
                {
                    ans=i;
                    return ans;
                }
            }
            if(prefix[i] == sum - nums[i] - prefix[i])
            {
                ans=i;
                return ans;
            }
        }
        return -1;
    }
};