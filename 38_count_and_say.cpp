class Solution {
public:
    string countAndSay(string str){
        int i;
        char temp = str[0];
        int num = 0;
        string ans = "";
        for(i = 0; i < str.size(); ++i){
           if(temp != str[i]){
               ans = ans + static_cast<char>(num + '0');
               ans = ans + temp; 
               num = 1;
               temp = str[i];
               if(i == str.size() - 1){
                   ans = ans + static_cast<char>(num + '0');
                   ans = ans + temp; 
               }
           } 
           else{
               num += 1;
               if(i == str.size() - 1){
                   ans = ans + static_cast<char>(num + '0');
                   ans = ans + temp; 
               }
           }
        }
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 0; i < n - 1; ++i){
            ans = countAndSay(ans);   
        }
        return ans;
    }
};