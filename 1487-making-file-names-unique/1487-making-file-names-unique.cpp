class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string>v;
        unordered_map<string,int>mp;
        for(int i=0;i<names.size();i++)
        {
            mp[names[i]]++;
            if(mp[names[i]]==1)
                v.push_back(names[i]);
            else
            {
                int k=mp[names[i]]-1;
                while(true)
                {
                    string t = names[i]+"("+to_string(k)+")";
                    if(mp.find(t)!=mp.end())
                        k++;
                    else
                        break;
                }
                string temp = names[i]+"("+to_string(k)+")";
                v.push_back(temp);
                mp[temp]++;
            }
        }
        return v;
    }
};