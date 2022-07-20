class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        
        int n = a.size();
        int m = b.size();
        int i=0 , j=0;
        
        vector<vector<int>> ans;
        
        while(i<n and j<m)
        {
            if(a[i][1] >= b[j][0] and a[i][0] <= b[j][1])
            {
                int low = max(a[i][0] , b[j][0]);
                int hig = min(a[i][1] , b[j][1]);
                ans.push_back({low , hig});
            }
            a[i][1] < b[j][1] ? i++ : j++;
        }
        return ans;
    }
};
