class Solution {
public:
    void inorder(vector<int> & ans, TreeNode * root){
        if(root->left != nullptr){
            inorder(ans, root->left);
        }
        ans.push_back(root->val);
        if(root->right!= nullptr){
            inorder(ans, root->right);
        }
    }
    bool isValidBST(TreeNode * root){
        vector<int> temp;
        if(root == nullptr){
            return true;
        }
        inorder(temp, root);
        for(int i = 0; i < temp.size() - 1; ++i){
            if(temp[i] >= temp[i+1]){
                return false;
            } 
        }
        return true;
        
    }
};