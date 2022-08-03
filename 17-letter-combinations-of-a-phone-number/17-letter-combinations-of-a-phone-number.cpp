class Solution {
public:
    
    void setmap(map<char,string>& map)
    {
        map['2']="abc";
        map['3']="def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
    }
    
    void solve(int i,string& digits,vector<string>&ans,string temp,map<char,string>&map)
    {
        if(i == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        for(char a:map[digits[i]])
        {
            solve(i+1,digits,ans,temp+a,map);
        }
    }
    vector<string> letterCombinations(string digits) {
        string temp="";
        vector<string> ans;
        if(digits.empty())  return ans;
        map<char,string> map;
        setmap(map);
        solve(0,digits,ans,temp,map);
        return ans;
    }
};