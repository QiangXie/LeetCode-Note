class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0){
            return 0;
        }
        int ans = 0;
        int i = s.size() - 1;
        while(s[i] == ' ' && i >= 0){
            i--;
        }
        while(s[i] != ' ' && i >= 0){
            ans += 1;
            i--;
        }
        return ans;
    }
};