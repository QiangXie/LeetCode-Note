class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend >= 0) ^ (divisor > 0) ? -1 : 1;
        long long m = abs(static_cast<long long>(dividend));
        long long n = abs(static_cast<long long>(divisor));
        long long ans = 0;
        if(n > m){
            return 0;
        }
        else if(n == m){
            return sign; 
        }
        long long k = 1;
        while(n < m){
            n <<= 1;
            k <<= 1;
        }
        n >>= 1;
        k >>= 1;
        while(n >= abs(divisor)){
            while(m >= n){
                m -= n;
                ans += k;
            }
            n >>= 1;
            k >>= 1;
        }
        if(ans > INT_MAX && sign > 0){
            return INT_MAX;
        }
        else if(sign < 0 && sign*ans < INT_MIN){
            return INT_MIN;
        }
        else{
            return ans * sign;
        }
    }
};