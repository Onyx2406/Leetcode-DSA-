class Solution {
public:
    int diff=0;
    int maxAncestorDiff(TreeNode* root,int cmin = INT_MAX, int cmax = INT_MIN) {
	//here initialized two variables one is cmin which +infinity number and second one is -infinity number
        if(root==NULL)
            return 0;
        
        
        cmin = min(root->val, cmin);
		//checked min node
        cmax = max(root->val, cmax);
        //checked max node
        diff = max(diff,cmax-cmin);
		//in max i saved max difference 
        maxAncestorDiff(root->left,cmin,cmax);
        maxAncestorDiff(root->right,cmin,cmax);
       //here traversing as inorder traversing of DFS
        return diff;
		
    }
};