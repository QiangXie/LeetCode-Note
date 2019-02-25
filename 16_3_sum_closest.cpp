class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left, right;
        int ans, diff=INT_MAX;
        for(int i = 0; i < nums.size() - 2; ++i){
            left = i + 1;
            right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > target){
                    if(sum - target < diff){
                        diff = sum - target;
                        ans = sum;
                    } 
                    right--;
                }
                else if(sum == target){
                    diff = 0; 
                    ans = target;
                    return ans;
                }
                else{
                    if(target - sum < diff){
                        diff = target - sum;
                        ans = sum;
                    }
                    left++;
                }
            }
        }
        return ans;
    }
};