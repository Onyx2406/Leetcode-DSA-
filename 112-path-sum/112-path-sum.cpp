class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false; 
        stack<pair<TreeNode*, int>> stk ; 
        stk.push({root,0});
        while(!stk.empty()){
            auto node = stk.top(); 
            int rs = node.second; TreeNode* curr = node.first; 
            stk.pop(); 
            if(curr->left == NULL && curr->right == NULL){
                if(rs + curr->val == targetSum)
                    return true;
            }
            
            if(curr->left != NULL)
                stk.push({curr->left, rs + curr->val});
            if(curr->right != NULL)
                stk.push({curr->right, rs + curr->val});
        }
        return false; 
    }
};