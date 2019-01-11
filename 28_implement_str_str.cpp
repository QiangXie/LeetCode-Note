class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        if(haystack.size() == 0){
            return -1;
        }
        for(int i = 0; i < haystack.size(); ++i){
            if(haystack[i] == needle[0]){
                bool equal_flag = true;
                for(int j = 0; j < needle.size(); ++j){
                    if(i+j >= haystack.size() || haystack[i+j] != needle[j]){
                        equal_flag = false; 
                    }    
                }
                if(equal_flag){
                    return i;
                }
            } 
        }
        return -1; 
    }
};