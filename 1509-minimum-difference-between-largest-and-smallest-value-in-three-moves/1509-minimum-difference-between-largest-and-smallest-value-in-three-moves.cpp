class Solution {
public:
    int minDifference(vector<int>& a) {
        sort(begin(a),end(a));
        int n=a.size();
        if(n<=3)
            return 0;
        int i=3,j=n-1,r=INT_MAX;
        while(i>=0)
            r=min(r,a[j--]-a[i--]);
        return r;
    }
};