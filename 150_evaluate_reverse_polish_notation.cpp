class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); ++i){
            if(tokens[i].size() == 1 && tokens[i][0] == '*'){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            }  
            else if(tokens[i].size() == 1 && tokens[i][0] == '+'){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }  
            else if(tokens[i].size() == 1 && tokens[i][0] == '-'){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }  
            else if(tokens[i].size() == 1 && tokens[i][0] == '/'){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }  
            else{
                int sign = 1;
                string num = "";
                if(tokens[i][0] == '-'){
                    sign = -1; 
                    for(int j = 1; j < tokens[i].size(); ++j){
                        num = num + tokens[i][j];
                    }
                }
                else{
                    num = tokens[i];
                }
                s.push(atoi(num.c_str())*sign);
            }
        }
        return s.top();
    }
};