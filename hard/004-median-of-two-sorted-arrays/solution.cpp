class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int half = (m + n + 1) / 2;
        int lo = 0, hi = m;
        while (lo <= hi) {
            int i = (lo + hi) / 2;
            int j = half - i;
            int nums1L = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1R = (i == m) ? INT_MAX : nums1[i];
            int nums2L = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2R = (j == n) ? INT_MAX : nums2[j];
            if (nums1L <= nums2R && nums2L <= nums1R) {
                if ((m + n) % 2 == 1) return max(nums1L, nums2L);
                return (max(nums1L, nums2L) + min(nums1R, nums2R)) / 2.0;
            } else if (nums1L > nums2R) {
                hi = i - 1;
            } else {
                lo = i + 1;
            }
        }
        return 0.0;
    }
};