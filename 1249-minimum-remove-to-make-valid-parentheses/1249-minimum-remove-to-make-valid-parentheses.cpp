class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> x;
        
        for(int i = 0; i < n; ++i) {
            if (s[i] == '(') x.push(i); // Push i of '(' on Stack.
            if (s[i] == ')') {
                if(x.empty()) { // Have a '(' on Stack?
					// No! Slice it out.
                    s.erase(i, 1); 
                    i--; n--;
                } else {
					// Yes! It's a pair.
                    x.pop(); 
                }
            }
        }
        
        while(!x.empty()) { // Have any '(' left on Stack?
            s.erase(x.top(), 1); // Slice em.
            x.pop();
        }
        
        return s;
    }
};