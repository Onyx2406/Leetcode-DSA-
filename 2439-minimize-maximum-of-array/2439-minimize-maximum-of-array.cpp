class Solution {
public:
    bool isPossible(vector<int> &nums, int x) {
        long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > x) {
                if(nums[i]-x > sum) return false;
                sum -= (nums[i]-x);
            } else {
                sum += x-nums[i];
            }
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int lo = 0, hi = 1e9;
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            if(isPossible(nums, mid)) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};
