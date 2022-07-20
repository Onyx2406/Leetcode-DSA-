class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL || root2==NULL){
            if(root1==NULL && root2==NULL) return true;
            return false;
        }
		
        if(root1->val!=root2->val){
            return false;
        }
		
        return (flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right)) || (flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left));
    }
};