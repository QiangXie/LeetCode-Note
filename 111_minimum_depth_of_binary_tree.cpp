class Solution {
public:
    int minDepth(TreeNode * root, int depth){
        if(root->left == nullptr && root->right == nullptr){
            return depth;
        }
        else if(root->left == nullptr && root->right != nullptr){
            return minDepth(root->right, depth+1);
        }
        else if(root->left != nullptr && root->right == nullptr){
            return minDepth(root->left, depth+1);
        }
        else{
            return min(minDepth(root->left, depth+1), minDepth(root->right, depth+1));
        }
    }
    int minDepth(TreeNode* root) {
       if(root != nullptr){
           return minDepth(root, 1);
       }
       else{
           return 0;
       }
    }
};