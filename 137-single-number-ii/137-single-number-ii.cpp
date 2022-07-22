class Solution {
public:
int singleNumber(vector<int> nums) {
int n = nums.size();
if(n==1) return nums[0];

    // sort the vector to create clusters of same elements
    sort(nums.begin(), nums.end());
    
    // Edge cases
    if(nums[1]!=nums[0]){
        return nums[0];
    }
    if(nums[n-1]!=nums[n-2]){
        return nums[n-1];
    }
    
    // if element before start of cluster isn't equal to current element then it's the answer
    for(int i=1; i<n; i+=3){
        if(nums[i-1]!=nums[i]){
            return nums[i-1];
        }
    }
    
    return NULL; // if n==2
}
};