class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> a,b;
        a=unordered_set<int>(nums1.begin(),nums1.end());
        b=unordered_set<int>(nums2.begin(),nums2.end());
        for(auto i=a.begin();i!=a.end();i++)
        {
            if(a.count(*i)==b.count(*i))
                ans.push_back(*i);
        }
        return ans;
    }
};