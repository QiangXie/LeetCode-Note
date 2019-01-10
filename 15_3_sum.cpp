class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); j++){
                int sum_two = nums[i] + nums[j];
                if(j+1 < nums.size()){
                    auto find_result = find(nums.begin()+j+1, nums.end(), -sum_two);
                    if(find_result != nums.end()){
                        vector<int> temp{nums[i], nums[j], *find_result};
                        if(find(ans.begin(), ans.end(), temp) == ans.end()){
                           ans.push_back(temp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};