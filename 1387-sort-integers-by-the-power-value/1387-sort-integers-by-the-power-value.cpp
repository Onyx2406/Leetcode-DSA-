class Solution {
public:
      unordered_map<int,int> dp;
    static bool comp(pair<int,int>&a, pair<int,int>&b)
    {
        
        if(a.first==b.first)
         return a.second<b.second;
        
         return a.first<b.first;
        
        
        
        
    }
    int f(int n)
    {
        if(n==1) return 0;
        if(dp[n]!=0) return dp[n];
        if(n%2==0)
         return dp[n]=1+f(n/2);
         return dp[n]=1+f(3*1LL*n+1);
    }
    int getKth(int lo, int hi, int k) {
       vector<pair<int,int>>v;
    
        for(int i=lo;i<=hi;i++)
        {
            v.push_back({f(i),i});            
        }
        
        sort(v.begin(),v.end(),comp);
       
        return v[k-1].second;
    }
};