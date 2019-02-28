class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2){
            return;
        }
        bool bigest = true;
        
        for(int i = nums.size() - 2; i >= 0; --i){
            int min = INT_MAX;
            int index;
            for(int j = i + 1; j <= nums.size()-1; ++j){
                if(nums[j] > nums[i] && nums[j] < min){
                    min = nums[j];
                    index = j;
                }
            }
            if(min != INT_MAX){
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                bigest = false;
                if(i+1 < nums.size() - 1){
                    sort(nums.begin() + i + 1, nums.end());
                }
                return;
            }
        }
        
        if(bigest){
            sort(nums.begin(), nums.end());
        }
        return;
    }
};