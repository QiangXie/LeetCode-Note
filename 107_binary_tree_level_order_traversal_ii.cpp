struct TreeNodeWithDepth{
    TreeNode * node;
    int depth;
};
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        stack<vector<int>> stack_ans;
        queue<TreeNodeWithDepth> temp_queue;
        TreeNodeWithDepth root_with_depth;
        root_with_depth.node = root;
        root_with_depth.depth = 1;
        temp_queue.push(root_with_depth);
        vector<int> temp;
        int depth = 1;
        while(!temp_queue.empty()){
            if(temp_queue.front().depth != depth){
                stack_ans.push(temp);
                temp.clear();
                depth = temp_queue.front().depth;
            }
            temp.push_back(temp_queue.front().node->val);
            if(temp_queue.front().node->left != nullptr){
                TreeNodeWithDepth temp;
                temp.node = temp_queue.front().node->left;
                temp.depth = temp_queue.front().depth+1;
                temp_queue.push(temp);
            }
            if(temp_queue.front().node->right!= nullptr){
                TreeNodeWithDepth temp;
                temp.node = temp_queue.front().node->right;
                temp.depth = temp_queue.front().depth+1;
                temp_queue.push(temp);
            }
            temp_queue.pop();
        }
        stack_ans.push(temp);
        while(!stack_ans.empty()){
            ans.push_back(stack_ans.top());
            stack_ans.pop();
        }
        return ans;
    }
};