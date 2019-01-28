class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int dpn = nums[0];
        int temp = dpn;
        for(int i = 1; i < nums.size(); ++i){
            dpn = max(dpn, 0) + nums[i];
            if(dpn > temp)
                temp = dpn;
        }
        return temp;
    }
};