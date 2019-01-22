class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s_array;
		double ret = 0.0;

		s_array.insert(nums1.begin(), nums1.end());
		s_array.insert(nums2.begin(), nums2.end());
		vector<int> nums3(s_array.begin(), s_array.end());

		int size_count = s_array.size();
		if (size_count % 2 == 0)
		{
			ret = (nums3.at(size_count / 2) + nums3.at(size_count / 2 - 1)) / 2.0;
		}
		else
		{
			ret = nums3.at((size_count - 1) / 2);
		}

		return ret;
    }
};