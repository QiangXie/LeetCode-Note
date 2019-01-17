class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        int index, temp;
        for(index = 1,temp = nums[0]; index < nums.size(); ++index){
            if(nums[index] == temp){
                nums[index] = nums[0] - 1;
            }
            else{
                temp = nums[index];
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == nums[0] - 1){
                int j = i+1;
                while(j < nums.size()){
                    if(nums[j] != nums[0] - 1){
                        break;
                    }
                    j++;
                }
                if(j == nums.size()){
                    return i;
                }
                else{
                    nums[i] = nums[j];
                    nums[j] = nums[0] - 1;
                }
            }
        }
        return nums.size();
    }
};