class Solution {
public:
    int add_recursive(int num){
        int sum = 0;
        while(num){
           sum += num%10;
           num /= 10;  
        }
        if(sum / 10){
            return add_recursive(sum);
        }
        else{
            return sum;
        }
    }
    int addDigits(int num) {
        return add_recursive(num);  
    }
};