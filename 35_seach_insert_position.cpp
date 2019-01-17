class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans;
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        if(target < nums[left]){
            return left;
        }
        if(target > nums[right]){
            return right + 1;
        }
        while(true){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                if(nums[left] < target){
                    if(left + 1 == mid){
                        return mid;
                    }
                    else{
                        right = mid;
                        mid = (right + left) / 2;
                    }
                }
                else if(nums[left] == target){
                    return left;
                }
            }
            else if(nums[mid] < target){
                if(nums[right] > target){
                    if(mid + 1 == right){
                        return right;
                    }
                    else{
                        left = mid;
                        mid = (right + left) / 2;
                    }
                }
                else if(nums[right] == target){
                    return right;
                }
            }
        }
    }
};