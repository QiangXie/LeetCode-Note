class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int len;
        for(int i = 0; i < s.size(); ++i){
            len = 1;
            for(int j = i + 1; j < s.size(); j++){
                bool repeat_flag = false;
                for(int h = i; h < j; ++h){
                    if(s[h] == s[j]){
                        repeat_flag = true;
                        break;
                    }
                }
                if(!repeat_flag){
                    len++;
                }
                else{
                    break;
                }     
            }
            if(ans < len){
                ans = len;
            }
        }
        return ans;
    }
};