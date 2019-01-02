class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0){
            return ans;
        }
        if(strs.size() == 1){
            return strs[0];
        }
        for(int i = 0; i < strs[0].size(); ++i){
            bool flag = true;
            for(int j = 1; j < strs.size(); ++j){
                if(strs[j].size() < i+1){
                    flag = false;
                    break;
                }
                else if(strs[j][i] != strs[0][i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans += strs[0][i];
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};