class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()) {
            int n = q.size();
            ++lvl;
            for(int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if(node -> left)    q.push(node -> left);
                if(node -> right)    q.push(node -> right);
                if(node -> left == NULL && node -> right == NULL)   return lvl;
            }
        }
        return -1;
    }
};