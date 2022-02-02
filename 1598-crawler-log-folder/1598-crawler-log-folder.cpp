class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<char> st;
        
        for(string &i:logs)
        {
            if(i == "../")
            {
                if(st.size()!=0)
                    st.pop();
            }
            else if(i == "./")
            {
                continue;
            }
            else
            {
                st.push(1);
            }
        }
        return st.size();

    }
};