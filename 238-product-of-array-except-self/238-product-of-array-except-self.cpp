class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        
        int sum=1,sum1=1;
        int ok=0;
        unordered_map<int,int> m;
        vector<int> v;
        
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            if(nums[i] == 0)
            {
                ok=1;
            }
        }
        if(m[0] > 1)
        {
            for(int i=0;i<n;i++)
            {
                v.push_back(0);
            }
            return v;
        }
        if(ok)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i] == 0)
                {
                    continue;
                }
                else
                {
                    sum1*=nums[i];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            sum*=nums[i];
        }
        if(ok)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i] != 0)
                {
                    v.push_back(0);
                }
                else
                {
                    v.push_back(sum1);
                }
            }
            return v;
        }
        
        for(int i=0;i<n;i++)
        {
            v.push_back(sum/nums[i]);
        }
        return v; 
    }
};