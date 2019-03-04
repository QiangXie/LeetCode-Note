class Solution {
public:
    void switchIndex(vector<int>& nums, int i){
        if(nums[nums[i]-1] > 0 && nums[nums[i]-1] < i){
            switchIndex(nums, nums[i]-1);
        }
        int temp;
        temp = nums[nums[i]-1];
        nums[nums[i]-1] = nums[i];
        nums[i] = temp;
    }
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0 && nums[i] - 1 < nums.size() && nums[i]-1 != i){
                switchIndex(nums, i);
            } 
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0 && nums[i] - 1 < nums.size() && nums[i]-1 != i){
                switchIndex(nums, i);
            } 
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};