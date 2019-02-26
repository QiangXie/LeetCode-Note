class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4){
            return ans;
        }
        sort(nums.begin(), nums.end());
        int left, right;
        for(int i = 0; i < nums.size() - 3; ++i){
            for(int j = i+1; j < nums.size(); ++j){
                left = j+1;
                right = nums.size() - 1;
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        vector<int> temp;
                        temp.clear();
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        if(find(ans.begin(), ans.end(), temp) == ans.end()){
                            ans.push_back(temp);
                        }
                        left++;
                    }
                    else if(sum > target){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};