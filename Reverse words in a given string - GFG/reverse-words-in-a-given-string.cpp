// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
   { 
       // code here 
        vector<string>v;
     string str="",ans="";
     
     for(int i=0;i<s.size();i++){
         if(s[i]!='.'){
             str=str+s[i];
         }
         else{
             v.push_back(str);
             str="";
         }
     }
     v.push_back(str);
     for(int i=v.size()-1;i>=0;i--){
         ans=ans+v[i]+".";
     }
     ans.pop_back();
     return ans;
   } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends