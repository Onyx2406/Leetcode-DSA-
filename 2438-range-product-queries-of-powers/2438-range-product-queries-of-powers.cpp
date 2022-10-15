class Solution {
public:

    int mod=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        vector<int> ans;
        vector<long long int> p;
        int n1=n;
        while(n1>0)
        {
            long long int x=log2(n1);
            p.push_back((pow(2,x)));
            n1-=pow(2,x);
        }
        sort(p.begin(),p.end());
       
        for(int i=0;i<q.size();i++)
        {
            long long pro=1;
            for(int j=q[i][0];j<=q[i][1];j++)
            {
                pro=(pro%mod*p[j]%mod)%mod;
            }
            ans.push_back(pro%mod);
        }
       
        return ans;
    }
};