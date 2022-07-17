class Solution {
private :
    void func(vector<int>& nums, int i, int n){
        if(i == n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        func(nums, i + 1, n);   // Pick the element
        v.pop_back();
        func(nums, i + 1, n);   // Non Pick the element
    }    
    
public:
    vector<int> v;
    vector<vector<int>> ans;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        func(nums, 0, n);
        return ans;
    }
};