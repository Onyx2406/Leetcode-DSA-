/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty())
        {
            int breadth = q.size(); // breadth is the number of nodes at the current level
            sum = 0; // sum will be 0 until final level or deepest level is reached
            for(int i = 0; i<breadth; i++)
            {
                TreeNode* front = q.front(); q.pop();
                sum += front->val; // at each level sum gets updated
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        return sum;
    }
};