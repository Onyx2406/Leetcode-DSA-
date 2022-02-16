// class Solution {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
//         priority_queue<pair<int,vector<int>>> pq;
//         // vector<pair<int, vector<int>>>> pq;
//         vector<vector<int>> v;
//         int n1 = nums1.size(), n2 = nums2.size();
        
//         for(int i=0;i<n1;i++)
//         {
//             for(int j=0;j<n2;j++)
//             {
//                 int sum=nums1[i]+nums2[j];
//                 vector<int> vv{nums1[i], nums2[j]};
//                 if(pq.size() < k)
//                 {
//                     pq.push({sum,vv});
//                 }
//                 else if(pq.top().first > sum)
//                 {
//                     pq.pop();
//                     pq.push({sum,vv});
//                 }
//             }
//         }
//         while(!pq.empty())
//             v.push_back(pq.top().second), pq.pop();
//         return v;
        
//     }
// };
typedef pair<pair<int,int>, int>pii;
struct comp
{
    bool operator()(const pair<pair<int,int>, int>&a, const pair<pair<int,int>, int>&b){
        return a.second > b.second;// min heap for sum
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>>ans;
        if(nums1.empty() || nums2.empty() || k == 0) return ans;
        
        priority_queue<pii, vector<pii>, comp>pq;
        pq.push({{0,0}, nums1[0]+nums2[0]}); // store first number indices and sum
        
        while(k-- > 0 && !pq.empty())
        {
            int idx_1 = pq.top().first.first;
            int idx_2 = pq.top().first.second;
            int sum = pq.top().second;
            pq.pop();
            
            ans.push_back({nums1[idx_1], nums2[idx_2]}); //  push vector as a result in ans
            if (idx_1 + 1 < nums1.size())
                pq.push({{idx_1 + 1, idx_2}, nums1[idx_1+1]+nums2[idx_2]});
            if (idx_1 == 0 && idx_2 + 1 < nums2.size())
                pq.push({{idx_1, idx_2 + 1}, nums1[idx_1]+nums2[idx_2+1]});
        
            
        }
        return ans;
    }
};