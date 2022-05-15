class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int curr = 0;
            for (auto& num: nums) {
      
                curr += (num >> i) & 1;
            }

            ans = max(ans, curr);
        }
        return ans;
    }
};