// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        set<int> s;
        sort(arr,arr+N);
        int start=0;
        int ans = 0;
        vector<int> v;
        v.push_back(arr[0]);
 
        for (int i = 1; i < N; i++) 
        {
            if (arr[i] != arr[i - 1])
                v.push_back(arr[i]);
        }
        int best=0;
        int res = arr[0];
        for(int i=1;i<v.size();i++)
        {
            if(v[i] == v[i-1] + 1)
            {
                ans++;
                best=max(best,ans);
            }
            else
            {
                ans=0;
                start=i;
            }
        }
        return best+1;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends