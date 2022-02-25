class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> m;
        
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto e:m)
        {
            pq.push({e.second,e.first});
        }
        while(pq.size()!=0)
        {
            pair<int,char> t = pq.top();
            pq.pop();
            while(t.first--)
            {
                ans+=t.second;
            }
        }
        return ans;
        
    }
};