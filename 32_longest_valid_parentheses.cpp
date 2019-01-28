class Solution {
public:
    int longestValidParentheses(string s) {
        if( s.size() == 0){
            return 0;
        }
        int ans= 0;
        int start = 0;
        stack<int> stack;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                stack.push(i);
            }
            else{
                if(stack.empty()){
                    start = i+1;
                }
                else{
                    stack.pop();
                    if(stack.empty()){
                        ans = max(ans, i - start + 1);
                    }
                    else{
                        ans = max(ans, i - stack.top());
                    }
                }
            }
        }
        return ans;
    }
};