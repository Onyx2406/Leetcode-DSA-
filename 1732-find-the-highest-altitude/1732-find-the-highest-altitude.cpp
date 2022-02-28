class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        vector<int> v;
        
        v.push_back(0);
        v.push_back(gain[0]);
        
        for(int i=1;i<gain.size();i++)
        {
            v.push_back(v[i] + gain[i]);
        }
        sort(v.begin(),v.end());
        int ans = v[v.size()-1];
        return ans;
    }
};