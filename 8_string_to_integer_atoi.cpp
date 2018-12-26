class Solution {
public:
    int myAtoi(string str) {
        int i;
        int sign = 1;
        unsigned long ans = 0;
        for(i = 0; i < str.size(); ++i){
           if(str[i] != ' '){
               break;
           }
        }
        if(str[i] == '+'){
            i++;
        }
        else if(str[i] == '-'){
            sign = -1;
            i++;
        }
        else if (str[i] < '0' || str[i] > '9'){
            return 0;
        }
        for(int j = i; j < str.size(); ++j){
            if(str[j] >= '0' && str[j] <= '9'){
                if(ans > 214748364){
                    if(sign > 0){
                        return 2147483647;
                    }
                    else{
                        return -2147483648;
                    }
                }
                else if(ans == 214748364){
                    if(sign > 0 && str[j] - '0' > 7){
                        return 2147483647;
                    }
                    else if(sign < 0 && str[j] - '0' > 8){
                        return -2147483648;
                    }
                }
                ans = ans*10 + (str[j] - '0');
            }
            else{
                break;
            }
        }
        return ans*sign;
    }
};