class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0){
            return;
        }
        else{
            int i = 0;
            while(i < nums.size()){
                while(i < nums.size() && nums[i] != 0){
                    i++;
                }
                if(i == nums.size()){
                    break;
                }
                else{
                    int j = i + 1;
                    while(j < nums.size() && nums[j] == 0){
                        j++;
                    }
                    if(j == nums.size()){
                        break;
                    }
                    cout << i << " " << j << " " <<  nums[i] << " " << nums[j] << endl;
                    nums[i] = nums[j];
                    nums[j] = 0;
                    i++;
                }
            }
        }
        return;
    }
};