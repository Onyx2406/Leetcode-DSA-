// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string S) 
	{
	    unordered_map<char,int> m;
	    
	    int n = S.size();
	    
	    for(int i=0;i<n;i++)
	    {
	        m[S[i]]++;
	    }
	    string ans="";
	    
	    for(int i=0;i<n;i++)
	    {
	        if(m[S[i]] > 0)
	        {
	            ans+=S[i];
	            m[S[i]]=0;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}  // } Driver Code Ends