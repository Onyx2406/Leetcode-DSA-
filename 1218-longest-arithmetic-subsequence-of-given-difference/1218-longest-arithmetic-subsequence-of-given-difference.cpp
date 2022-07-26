class Solution {
public:
  
    int longestSubsequence(vector<int>& arr, int dif) 
    {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            if(mp.find(arr[i]-dif)!=mp.end())
            {
                mp[arr[i]]=1+mp[arr[i]-dif];
            }
            else
                mp[arr[i]]=1;
            ans=max(ans,mp[arr[i]]);
        }
        return ans;
    }
};