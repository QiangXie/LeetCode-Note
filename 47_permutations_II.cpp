class Solution {
public:
    void permuteUnique(vector<vector<int>> & ans, vector<int> & temp, vector<int> & nums){
        if(nums.empty()){
            if(find(ans.begin(), ans.end(), temp) == ans.end()){
                ans.push_back(temp);
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            temp.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            permuteUnique(ans, temp, nums);
            nums.insert(nums.begin()+i, temp.back());
            temp.pop_back();
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        permuteUnique(ans, temp, nums);
        return ans;
    }
};