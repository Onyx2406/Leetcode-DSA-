class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end()); int n= nums.size();
        if(n==1 || n==2 || n==3 || n==4){ return 0; }
        
        int a= nums[n-4]-nums[0]; // kill 3 biggest elements
        int b= nums[n-3]-nums[1]; // kill 2 biggest elements + 1 smallest elements
        int c= nums[n-2]-nums[2]; // kill 1 biggest elements + 2 smallest elements
        int d= nums[n-1]-nums[3]; // kill 3 smallest elements
        
        return min(a, min(b, min(c,d)));
    }
};