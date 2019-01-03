class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){
            return 0;
        }
        int i = 0;
        while(true){
            while(nums[i] != val && i < nums.size()){
               i++; 
            }
            if(i == nums.size()){
                return i;
            }
            else{
                int j = i + 1;
                while(nums[j] == val && j < nums.size()){
                    j++;
                }
                if(j == nums.size()){
                    return i;
                }
                else{
                    nums[i] = nums[j];
                    nums[j] = val;
                }
            }
        }
    }
};