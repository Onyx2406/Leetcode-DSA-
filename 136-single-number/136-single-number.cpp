class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int count=nums[0];
        for(int i=1;i<n;i++)
        {
      count=count^nums[i];
        }
        return count;
    }
};