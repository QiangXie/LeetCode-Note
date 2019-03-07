class Solution {
public:
    void permute(vector<int>& nums, vector<int> & temp, vector<vector<int>> & ans){
        if(nums.empty()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            temp.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            permute(nums, temp, ans);
            nums.insert(nums.begin()+i, temp.back());
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        permute(nums, temp, ans);
        return ans;
    }
};