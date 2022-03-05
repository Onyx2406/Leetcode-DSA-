class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int ans=0;
        int N = INT_MIN;
        int n = nums.size();
        int a = 0;
        int res = 0;
        
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            int ans=0;
            for(int j=0;j<n-1;j++)
            {
                if(nums[j] == key && nums[j+1] == nums[i])
                {
                    ans++;
                }
            }
            if(ans > N)
            {
                N=ans;
                res=nums[i];
            }
        }
        return res;
    }
};