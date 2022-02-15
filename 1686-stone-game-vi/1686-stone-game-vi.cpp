class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b){
        return a.first+a.second>b.first+b.second;
    }
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<pair<int,int>> v;
        int i,j,k,n=a.size();
        for(i=0;i<n;i++){
            v.push_back({a[i],b[i]});
        }
        sort(v.begin(),v.end(),comp);
        int al=0,bb=0;
        for(i=0;i<n;i++){
            if(i%2)
                bb+=v[i].second;
            else
                al+=v[i].first;
        }
        if(al>bb)
            return 1;
        else if(al==bb)
            return 0;
        else
            return -1;
     }
};