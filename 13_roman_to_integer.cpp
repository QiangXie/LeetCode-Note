class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()){
            return 0;
        }
        int ans = 0;
        for(int i = s.size()-1; i >= 0;){
            switch (s[i]){
                case 'I':
                    ans += 1;
                    i--;
                    break;
                case 'V':
                    if(i-1 >= 0 && s[i-1] == 'I'){
                        ans += 4;
                        i -= 2;
                    }
                    else{
                        ans += 5;
                        i--;
                    }
                    break;
                case 'X':
                    if(i-1 >= 0 && s[i-1] == 'I'){
                        ans += 9;
                        i -= 2;
                    }
                    else{
                        ans += 10;
                        i--;
                    }
                    break;
                case 'L':
                    if(i-1 >= 0 && s[i-1] == 'X'){
                        ans += 40;
                        i -= 2;
                    }
                    else{
                        ans += 50;
                        i--;
                    }
                    break;
                case 'C':
                    if(i-1 >= 0 && s[i-1] == 'X'){
                        ans += 90;
                        i -= 2;
                    }
                    else{
                        ans += 100;
                        i--;
                    }
                    break;
                case 'D':
                    if(i-1 >= 0 && s[i-1] == 'C'){
                        ans += 400;
                        i -= 2;
                    }
                    else{
                        ans += 500;
                        i--;
                    }
                    break;
                case 'M':
                    if(i-1 >= 0 && s[i-1] == 'C'){
                        ans += 900;
                        i -= 2;
                    }
                    else{
                        ans += 1000;
                        i--;
                    }
            }
        }
        return ans;
    }
};