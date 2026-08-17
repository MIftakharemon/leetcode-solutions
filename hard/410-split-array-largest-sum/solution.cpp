class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long left = *max_element(nums.begin(), nums.end());
        long right = accumulate(nums.begin(), nums.end(), 0L);
        while (left < right) {
            long mid = left + (right - left) / 2;
            int count = 1, sum = 0;
            for (int num : nums) {
                if (sum + num > mid) { count++; sum = num; }
                else sum += num;
            }
            if (count <= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};