class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack<char> st;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(st.empty())  {st.push(s[i]);}
            else if(s[i] == ')' && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.size();
        
    }
};