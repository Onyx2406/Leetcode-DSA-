class Solution {
public:
    void postorder(TreeNode* &root, map<int,bool> mp, vector<TreeNode*>& res){
        
        if(root==NULL) return;
        postorder(root->left,mp,res);
        postorder(root->right,mp,res);
        
        if(mp[root->val]){
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            root=NULL;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector <int>& to_delete) {
        vector<TreeNode*> ans;
        map<int,bool> mp;
        int n=to_delete.size();
        for(int i=0;i<n;i++){
            mp[to_delete[i]]=true;
        }
        vector<TreeNode*> res;
        postorder(root,mp,res);
        if(root!=NULL) res.push_back(root);
        return res;
    }
};