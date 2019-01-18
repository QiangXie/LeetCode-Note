class Solution {
public:
    int maxDepth(TreeNode* root, int depth){
        if(root->left == nullptr && root->right == nullptr){
            return depth;
        }
        else if(root->left != nullptr && root->right != nullptr){
            return max(maxDepth(root->left, depth+1), maxDepth(root->right, depth+1));
        }
        else if(root->left != nullptr){
            return maxDepth(root->left, depth+1);
        }
        else{
            return maxDepth(root->right, depth+1);
        }
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int depth = 1;
        return maxDepth(root, depth);
    }
};