class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for(int i = 1; i < height.size(); ++i){
            for(int j = 0; j < height.size(); ++j){
                int h = j + i;
                if(h >= height.size()){
                    break;
                }
                int s = min(height[j], height[h]) * i;
                if(s > ans){
                    ans = s;
                }
            }
        }
        return ans;
    }
};