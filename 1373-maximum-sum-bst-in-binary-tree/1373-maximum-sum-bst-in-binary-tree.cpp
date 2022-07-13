class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        
        helper(root, ans);
        
        return ans;
    }
    
    tuple<int, int, int> helper(TreeNode* root, int& ans) { // min, max, sum
        if (not root) {
            // base case
            return {INT_MAX, INT_MIN, 0};
        }
        
        auto [leftMin, leftMax, leftSum] = helper(root->left, ans);
        auto [rightMin, rightMax, rightSum] = helper(root->right, ans);
        
        if (root->val > leftMax and root->val < rightMin) {
            // valid bst
            int sum = leftSum + root->val + rightSum;
            ans = max(ans, sum);

            return {min(root->val, leftMin), max(root->val, rightMax), sum};
        }
        
        // invalid bst
        return {INT_MIN, INT_MAX, 0};
    }
};