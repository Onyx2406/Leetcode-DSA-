class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    
    int n = nums.size();
    
    int first = n , last = -1;
    
    int left_max = INT_MIN , right_min = INT_MAX;
    
    for(int i=0;i<n;i++) {
        
        if(nums[i] < left_max) last = i;
        
        else left_max = nums[i];
        
        if(nums[n-i-1] > right_min) first = n-i-1;
        
        else right_min = nums[n-i-1];
    }
    
    if(first == n) return 0;
    return last-first+1;
}
};