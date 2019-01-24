class Solution {
public:
    string intToRoman(int num) {
        int num1000 = num / 1000;
        int num900 = (num % 1000) / 900;
        int num500 = ((num % 1000) % 900 ) / 500;
        int num400 = (((num % 1000) % 900) % 500)/400;
        int num100 = (((num % 1000) % 900) % 500)%400/100;
        int num90 = (num % 100) / 90;
        int num50 = ((num % 100) % 90) / 50;
        int num40 = (((num % 100) % 90) % 50) / 40;
        int num10 = (((num % 100) % 90) % 50) % 40/10;
        int num9 = (num % 10) / 9;
        int num5 = ((num % 10) % 9) / 5;
        int num4 = (((num % 10) % 9) % 5) / 4;
        int num1 = (((num % 10) % 9) % 5) % 4;
        string ans = "";
        if(num1000){
            for(int i = 0; i < num1000;++i){
                ans = ans + 'M';
            }
        }
        if(num900){
            for(int i = 0; i < num900;++i){
                ans = ans + "CM";
            }
        }
        if(num500){
            for(int i = 0; i < num500;++i){
                ans = ans + 'D';
            }
        }
        if(num400){
            for(int i = 0; i < num400;++i){
                ans = ans + "CD";
            }
        }
        if(num100){
            for(int i = 0; i < num100;++i){
                ans = ans + 'C';
            }
        }
        if(num90){
            for(int i = 0; i < num90;++i){
                ans = ans + "XC";
            }
        }
        if(num50){
            for(int i = 0; i < num50;++i){
                ans = ans + 'L';
            }
        }
        if(num40){
            for(int i = 0; i < num40;++i){
                ans = ans + "XL";
            }
        }
        if(num10){
            for(int i = 0; i < num10;++i){
                ans = ans + 'X';
            }
        }
        if(num9){
            for(int i = 0; i < num9;++i){
                ans = ans + "IX";
            }
        }
        if(num5){
            for(int i = 0; i < num5;++i){
                ans = ans + 'V';
            }
        }
        if(num4){
            for(int i = 0; i < num4;++i){
                ans = ans + "IV";
            }
        }
        if(num1){
            for(int i = 0; i < num1;++i){
                ans = ans + 'I';
            }
        }
        return ans;
    }
};