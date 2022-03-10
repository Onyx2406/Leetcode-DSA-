class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
		int sum = 0;
        for (int index = 0; index < nums.size(); index++){
            sum += nums[index];
			if (sum < nums[index]){
				sum = nums[index];
			}
			if (maxSum < sum){
				maxSum = sum;
			}
        }
        return maxSum;
    }
};