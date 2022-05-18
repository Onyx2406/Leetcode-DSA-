class Solution {
public:
    int f( vector<int> &nums, int ip, int fp){
        
        if(ip == 0) return (nums[ip] >= fp-ip) ? 1 : 0;
        
        if(nums[ip] >= fp-ip){
            return f(nums, ip-1, ip);
        }
        else{
            return f(nums, ip-1, fp);
        }
    }
    
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        return f(nums, n-2, n-1);
    }
};