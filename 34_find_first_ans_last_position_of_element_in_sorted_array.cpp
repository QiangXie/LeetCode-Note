class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if(nums.empty()){
            return ans;
        }
        if(nums.size() == 1){
            if(nums[0] == target){
                ans[0] = 0;
                ans[1] = 0;
                return ans;
            }
            else{
                return ans;
            }
        }
        int left = 0;
        int right = nums.size() - 1;
        int left_cache = INT_MIN;
        int right_cache = INT_MIN;
        while(!(right == right_cache && left == left_cache)){
            right_cache = right;
            left_cache = left;
            int mid = (left + right)/2;
            if(nums[mid] == target){
                if(mid == 0 || nums[mid-1] != target){
                    ans[0] = mid;
                    break;
                } 
                else{
                    right = mid;
                }
            }
            else if(nums[mid] > target){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        left = 0;
        right = nums.size() - 1;
        left_cache = INT_MIN;
        right_cache = INT_MIN;
        while(!(right == right_cache && left == left_cache)){
            right_cache = right;
            left_cache = left;
            int mid = (left + right)/2;
            if(nums[mid] == target){
                if(mid == nums.size() - 1 || nums[mid+1] != target){
                    ans[1] = mid;
                    break;
                } 
                else{
                    left = mid;
                }
            }
            else if(nums[mid] > target){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        if(nums[right] == target){
            ans[1] = right;
            if(nums[right-1] != target){
                ans[0] = right;
            }
        }
        return ans;
    }
};