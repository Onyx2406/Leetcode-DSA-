// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         stack<int> st1;
//         stack<int> st2;
        
//         for(auto i:s)
//         {
//             if(s[i] != '#')
//                 st1.push(i);
//             else
//                 st1.pop();
//         }
//         string ans1="";
//         string ans2="";
        
//         while(!st1.empty())
//         {
//             ans1+=st1.top();
//             st1.pop();
//         }
//         for(auto i:t)
//         {
//             if(t[i] != '#')
//                 st2.push(i);
//             else
//                 st2.pop();
//         }
        
//         while(!st2.empty())
//         {
//             ans2+=st2.top();
//             st2.pop();
//         }
        
//         return ans1==ans2;
//     }
class Solution 
{
public:
    string helper(string s)
    {
        stack<char>stk;
        for(auto it:s)
        {
            if(it!='#')
            {
                stk.push(it);
            }
            else if(!stk.empty())
            {
                stk.pop();
            }
        }
        string ans="";
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
    bool backspaceCompare(string S, string T) //to compare!
    {
        return helper(S)==helper(T);
    }
};