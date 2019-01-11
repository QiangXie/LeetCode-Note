class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::map<char, string> num_2_str {{'2', "abc"},
                                          {'3', "def"},
                                          {'4', "ghi"},
                                          {'5', "jkl"},
                                          {'6', "mno"},
                                          {'7', "pqrs"},
                                          {'8', "tuv"},
                                          {'9', "wxyz"}};
        vector<string> ans;
        queue<string> temp_ans;
        temp_ans.push("");
        if(digits.size() == 0){
            return ans;
        }
        else{
            for(int i = 0; i < digits.size(); i++){
               while(temp_ans.front().size() == i){
                   for(int j = 0; j < num_2_str[digits[i]].size(); j++){
                       temp_ans.push(temp_ans.front() + num_2_str[digits[i]][j]);
                   }
                   temp_ans.pop();
               } 
            }
            while(!temp_ans.empty()){
                ans.push_back(temp_ans.front());
                temp_ans.pop();
            }
            return ans;
        }
    }
};