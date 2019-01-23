class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if(J.size() == 0 || S.size() == 0){
            return 0;
        }
        int ans = 0;
        for(int i = 0; i < S.size(); ++i){
            if(find(J.begin(), J.end(), S[i]) != J.end()){
                ans += 1;
            }
        }
        return ans;
    }
};