class Solution {
public:
    string decodeString(string s) {
        stack<char> stack;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ']')
            {
                string decodedstring = "";
                
                while(stack.top() != '[')
                {
                    decodedstring += stack.top();
                    stack.pop();
                }
                stack.pop();
                
                int base = 1;
                int k = 0;
                
                while(!stack.empty() && isdigit(stack.top())){
                    k = k + (stack.top() - '0')*base;
                    stack.pop();
                    base *= 10;
                }
                int currentLen = decodedstring.size();
                
                while(k!=0)
                {
                    for(int j=decodedstring.size()-1;j>=0;j--)
                    {
                        stack.push(decodedstring[j]);
                    }
                    k--;
                }
            }
            else
            {
                stack.push(s[i]);
            }
        }
        string result;
        for(int i=stack.size()-1;i>=0;i--)
        {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};