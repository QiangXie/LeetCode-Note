class Solution {
public:
    void combinationSum2(vector<vector<int>> & ans, vector<int>& candidates, vector<int> temp, int start, int target){
        if(target == 0){
            if(find(ans.begin(), ans.end(), temp) == ans.end()){
                ans.push_back(temp);
            }
            return;
        }
        for(int i = start; i < candidates.size(); ++i){
            if(candidates[i] <= target){
                temp.push_back(candidates[i]);
                combinationSum2(ans, candidates, temp, i+1, target-candidates[i]);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum2(ans, candidates, temp, 0, target);
        return ans;
    }
};