class Solution {
public:
int lengthofLIS(vector<int> nums)
{
    int n = nums.size();
    vector<int> lis_vec;
    lis_vec.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > lis_vec.back())
        {
            lis_vec.push_back(nums[i]);
        }
        else
        {
            int idx = lower_bound(lis_vec.begin(), lis_vec.end(), nums[i]) - lis_vec.begin();
            lis_vec[idx] = nums[i];
        }
    }

    return lis_vec.size();
}
    bool increasingTriplet(vector<int>& nums) {
        return lengthofLIS(nums)>=3;
    }
};