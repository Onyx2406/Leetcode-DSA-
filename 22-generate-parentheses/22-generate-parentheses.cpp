class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n)
    {
        int open=0,close=0;
        gen(open,close,n,"");
        return ans;
    }
private:
    void gen(int open,int close,int n,string s)
    {
        if((n == open) && (n == close))
        {
            ans.push_back(s);
            return;
        }
        if(open < n)
        {
            gen(open+1,close,n,s+"(");
        }
        if(close < open)
        {
            gen(open,close+1,n,s+")");
        }
        return;
    }
};