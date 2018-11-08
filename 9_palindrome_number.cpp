class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
           return false;
        }
        else{
            int ans = 0;
            for(int temp = x; temp != 0; temp /= 10){
               ans = ans*10 + (temp%10); 
            }
            if(ans == x){
                return true;
            }
            else{
                return false;
            }
        }
        
    }
};