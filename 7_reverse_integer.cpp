class Solution {
public:
    int reverse(int x) {
        unsigned int abs_value;
        unsigned long int ans = 0;
        int flag = 1;
        if(x < 0){
            flag = -1;    
            abs_value = abs(x);
        }    
        else{
            flag = 1;
            abs_value = abs(x);
        }
        cout << abs_value << "\n";
        for(unsigned int temp = abs_value; temp != 0; temp /= 10){
            int remainder = temp % 10;
            ans = ans*10 + remainder;
            if((flag == -1 && ans > 2147483648) || (flag == 1 && ans > 2147483647)){
                return 0;
            }
        }
        return ans*flag;
    }
};