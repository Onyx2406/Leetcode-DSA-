class Solution
{
    public:
        string removeKdigits(string nums, int k)
        {
            stack<char>st;
            for(int i=0;i<nums.size();i++){
                while(!st.empty()&&st.top()>nums[i]&&k>0){  //Delete the element if it is greater than its next element
                    k--;
                    st.pop();
                }
                st.push(nums[i]);
            }
            while(k--){  //if we have some k to delete the delete the larger element
                st.pop();
            }
            string ans="";
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            
            while(ans.size()>0&&ans[ans.size()-1]=='0'){  //To handle leading zero's
                ans.pop_back();
            }
            reverse(ans.begin() , ans.end());
            if(ans.size()==0) return "0";  // if we deleted all elements
            return ans;
        }
    
    
};