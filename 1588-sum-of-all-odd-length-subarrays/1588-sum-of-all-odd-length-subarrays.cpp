class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
     int n = arr.size() ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            int no_of_subarray = (n - i) * (i + 1) ;
            int no_of_odd_subarray = (no_of_subarray + 1) / 2 ;
            int contribution = no_of_odd_subarray * arr[i] ;
            ans = ans + contribution ;
        }
        return ans ;
    }
};