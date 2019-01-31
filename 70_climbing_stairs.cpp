class Solution {
public:
    int climbStairs(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        vector<int> dpn(n + 1); 
        dpn[0] = 0;
        dpn[1] = 1;
        dpn[2] = 2;
        for(int i = 3; i < n + 1; ++i){
            dpn[i] = dpn[i - 2] + dpn[i - 1];
        }
        return dpn[n];
    }
};