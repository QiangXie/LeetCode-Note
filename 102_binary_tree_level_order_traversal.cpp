/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        std::queue<TreeNode*> temp_stack_1;
        std::queue<TreeNode*> temp_stack_2;
        vector<int> temp;
        temp.push_back(root->val);
        if(root->left != nullptr){
            temp_stack_1.push(root->left);
        }
        if(root->right != nullptr){
            temp_stack_1.push(root->right);
        }
        ans.push_back(temp);
        temp.clear();
        while(true){
            if(!temp_stack_1.empty()){
                while(!temp_stack_1.empty()){
                    temp.push_back(temp_stack_1.front()->val);
                    if(temp_stack_1.front()->left != nullptr){
                        temp_stack_2.push(temp_stack_1.front()->left);
                    }
                    if(temp_stack_1.front()->right != nullptr){
                        temp_stack_2.push(temp_stack_1.front()->right);
                    }
                    temp_stack_1.pop();
                }
                ans.push_back(temp);
                temp.clear(); 
            }
            else{
                return ans;     
            }
            if(!temp_stack_2.empty()){
                while(!temp_stack_2.empty()){
                    temp.push_back(temp_stack_2.front()->val);
                    if(temp_stack_2.front()->left != nullptr){
                        temp_stack_1.push(temp_stack_2.front()->left);
                    }
                    if(temp_stack_2.front()->right != nullptr){
                        temp_stack_1.push(temp_stack_2.front()->right);
                    }
                    temp_stack_2.pop();
                }
                ans.push_back(temp);
                temp.clear();
            }
            else{
                return ans;
            }
        }
         
    }
};