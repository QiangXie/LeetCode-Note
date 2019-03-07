class Solution {
public:
    void inorderTraversal(vector<int> & ans, TreeNode * root){
        if(root == nullptr){
            return;
        }
        inorderTraversal(ans, root->left);
        ans.push_back(root->val);
        inorderTraversal(ans, root->right);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        inorderTraversal(ans, root->left);
        ans.push_back(root->val);
        inorderTraversal(ans, root->right);
        return ans;
    }
};