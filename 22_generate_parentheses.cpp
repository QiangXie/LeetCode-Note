struct Item{
    string str = "";
    int numPre = 0;
    int numPos = 0;
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0){
            return ans;
        }
        if(n == 1){
            ans.push_back("()");
            return ans; 
        }
        Item first_item;
        first_item.str = "(";
        first_item.numPre = 1;
        first_item.numPos = 0;
        queue<Item> temp;
        temp.push(first_item);
        while(temp.front().numPre != n || temp.front().numPos != n){
            if(temp.front().numPre == temp.front().numPos){
                Item temp_ptr;
                temp_ptr.str = temp.front().str + '(';
                temp_ptr.numPos = temp.front().numPos;
                temp_ptr.numPre = temp.front().numPre + 1;
                temp.push(temp_ptr);
                temp.pop();
            }
            else if(temp.front().numPre > temp.front().numPos){
                Item temp_ptr;
                temp_ptr.str = temp.front().str + ')';
                temp_ptr.numPos = temp.front().numPos + 1;
                temp_ptr.numPre = temp.front().numPre;
                temp.push(temp_ptr);
                if(temp.front().numPre < n){
                    temp_ptr.str = temp.front().str + '(';
                    temp_ptr.numPos = temp.front().numPos;
                    temp_ptr.numPre = temp.front().numPre + 1;
                    temp.push(temp_ptr);
                }
                temp.pop();
            }
        }
        while(!temp.empty()){
            string temp_str;
            temp_str = temp.front().str;
            ans.push_back(temp_str);
            temp.pop();
        }
        return ans;
    }
};