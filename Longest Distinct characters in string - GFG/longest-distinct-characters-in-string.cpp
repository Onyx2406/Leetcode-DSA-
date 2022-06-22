// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

#define NO_OF_CHARS 256
int longestSubstrDistinctChars (string s)
{
    int n = s.size();
    int res=0;
    
    vector<int> lastidx(NO_OF_CHARS,-1);
    
    int i=0;
    
    for(int j=0;j<n;j++)
    {
        i = max(i,lastidx[s[j]]+1);
        
        res = max(res,j-i+1);
        
        lastidx[s[j]] = j;
    }
    return res;
}