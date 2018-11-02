class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(auto i = s.begin(); i != s.end(); ++i){
            auto j = i-1;
            auto h = i+1;
            while(h != s.end() && j != s.begin()-1 && *j == *h){
                h++;
                j--;
            }
            int temp_num = h - j - 1;
            if(temp_num > ans.size()){
                ans = "";
                for(auto k = j+1; k != h; ++k){
                    ans = ans + *k;
                } 
            }
            j = i;
            h = i+1;
            while(h != s.end() && j != s.begin()-1 && *j == *h){
                h++;
                j--;        
            }
            temp_num = h - j - 1;
            if(temp_num > ans.size()){
                ans = "";
                for(auto k = j+1; k != h; ++k){
                    ans = ans + *k;
                } 
            }
        }
        
        return ans;
    }
};