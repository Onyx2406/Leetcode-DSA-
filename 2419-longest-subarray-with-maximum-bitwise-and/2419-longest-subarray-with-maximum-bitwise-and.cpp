class Solution {
public:
     static int longestSubarray(const vector<int>& nums) {
        int k = 1;  // instead of k = *max_element(begin(nums), end(nums));
        int ans = 0;
        int curr = 0;
        for (int n : nums) {
            if (n == k) {
                ++curr;
                ans = max(ans, curr);
            } else if (n > k) {
                // We found a bigger number. Start all over.
                k = n;
                curr = 1;
                ans = 1;
            } else {
                curr = 0;
            }
        }
        return ans;
    }
};