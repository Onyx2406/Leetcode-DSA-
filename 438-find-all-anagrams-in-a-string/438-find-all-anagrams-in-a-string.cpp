class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> mp;
        for(auto el:p) mp[el]++;
        int i=0,j=0;
        vector<int> res;
        map<char,int> mp1;
        while(i<s.size()){
            while(j<s.size() && mp1[s[j]]<mp[s[j]]){
                mp1[s[j]]++;
                j++;
            }
            if(mp1==mp) res.push_back(i);
            mp1[s[i]]--;
            if(mp1[s[i]]==0) mp1.erase(s[i]);
            i++;
        }
        return res;
    }
};