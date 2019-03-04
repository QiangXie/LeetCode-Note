class Solution {
public:
    int search(vector<int> & nums, int left, int right, int target){
        int mid = (left + right) / 2;
        if(nums[left] == target){
            return left;
        }
        if(nums[right] == target){
            return right;
        }
        if(nums[mid] == target){
            return mid;
        }
        if(left == right - 1){
            return -1;
        }
        if(nums[mid] > nums[left] && nums[left] < target && nums[mid] > target){
            return search(nums, left, mid, target);
        }
        if(nums[mid] < nums[right] && nums[right] > target && nums[mid] < target){
            return search(nums, mid, right, target);
        }
        if(nums[mid] < nums[left] && (target > nums[left] || target < nums[mid])){
            return search(nums, left, mid, target);
        }
        if(nums[mid] > nums[right] && (target < nums[right] || target > nums[mid])){
            return search(nums, mid, right, target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        return search(nums, 0, nums.size()-1, target);
    }
};