class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        vector<int>ans;
        int i = 0;
        while(i<arr.size()){
            if(arr[i] >= 0){
                st.push(arr[i]);
                i++;
            }
            else{
                if(st.empty()){
                    st.push(arr[i]);
                    i++;
                }
                else{
                    int top = st.top();
                    if(top < 0 && arr[i] < 0){
                        st.push(arr[i]);
                        i++;
                    }
                    else if(top < abs(arr[i])){
                        st.pop();
                        if(st.empty()){
                            st.push(arr[i]);
                            i++; 
                        }
                    }
                    else if(top == abs(arr[i])){
                        st.pop();
                        i++;
                    }
                    else{
                        i++;
                    }
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};