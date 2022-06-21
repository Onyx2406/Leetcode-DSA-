// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        sort(array.begin(),array.end());
        
        if(n == 2)
        {
            if(array[0] == 1)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
        if(array[0] == 2)
        {
            return 1;
        }
        
        for(int i=0;i<n;i++)
        {
            if(array[i] + 2 == array[i+1])
            {
                return array[i]+1;
                
            }
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends