class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0){
            return;
        }
        if(m == 0){
            for(int i = 0; i < n; ++i){
                nums1[i] = nums2[i];
            }
            return;
        }
        int i = 0; 
        int j = 0;
        while(i < m && j < n){
            if(nums1[i] > nums2[j]){
                for(int h = m-1; h >= i; h--){
                    nums1[h+1] = nums1[h];
                }
                nums1[i] = nums2[j];
                j++;
                i++;
                m++;
            }
            else{
                i++;
            }
        }
        if(i == m){
            int k = 0;
            for(int h = j; h < n; ++h, ++k){
                nums1[m+k] = nums2[h];
            }
        }
        return;
    }
};