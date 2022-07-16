class Solution {
private:
    TreeNode* solve(vector<int> &nums,int s,int e){
        if(s > e){
            return NULL;
        }
        
        int mid = s + (e - s) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        // Recursively construct tree in left and right sub part
        
        root->left = solve(nums,s,mid-1);
        root->right = solve(nums,mid+1,e);
        return root;           
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = solve(nums,0,n-1);
        
        return root;
    }
};