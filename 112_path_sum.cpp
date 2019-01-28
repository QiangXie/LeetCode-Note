class Solution {
public:
    bool getPathSum(TreeNode * root, int curSum, int target){
        if(root->left == nullptr && root->right == nullptr){
            if(curSum + root->val == target){
                return true;
            }
            else{
                return false;
            }
        }
        else if(root->left != nullptr && root->right != nullptr){
            return getPathSum(root->left, curSum + root->val, target) |
                getPathSum(root->right, curSum + root->val, target);
        }
        else if(root->left != nullptr){
            return getPathSum(root->left, curSum + root->val, target);
        }
        else{
            return getPathSum(root->right, curSum + root->val, target);
        }
    }
    bool hasPathSum(TreeNode* root, int sum) {
        int curRootSum = 0;
        if(root == nullptr){
            return false;
        }
        return getPathSum(root, curRootSum, sum);
    }
};