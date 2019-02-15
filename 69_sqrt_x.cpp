class Solution {
public:
    int mySqrt(int x) {
        long n = 0;
        while(n*n < x){
            n++;
        }
        if(n*n == x){
            return n;
        }
        else{
            return n-1;
        }
    }
};