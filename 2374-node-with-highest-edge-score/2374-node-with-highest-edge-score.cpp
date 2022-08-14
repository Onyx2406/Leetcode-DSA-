class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
        unordered_map<long long,long long>u;
        int ans=-1;
        long long sum=INT_MIN;
        for(int i=0;i<edges.size();i++)
        {
            if(u.find(edges[i])!=u.end())
                u[edges[i]]=u[edges[i]]+i;
            else
                u[edges[i]]=i;
        }
        for(auto i:u)
        {
            if(i.second>sum)
            {
                sum=i.second;
                ans=i.first;
            }
            else if(i.second==sum and ans>i.first)
                ans=i.first;
        }
        return ans;
        
    }
};