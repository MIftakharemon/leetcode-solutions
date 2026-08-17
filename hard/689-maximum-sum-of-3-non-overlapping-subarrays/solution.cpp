class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> w(n - k + 1, 0);
        for (int i = 0; i < k; i++) w[0] += nums[i];
        for (int i = 1; i <= n - k; i++) w[i] = w[i - 1] - nums[i - 1] + nums[i + k - 1];
        vector<int> left(n - k + 1, 0);
        int best = 0;
        for (int i = 0; i <= n - k; i++) {
            if (w[i] > w[best]) best = i;
            left[i] = best;
        }
        vector<int> right(n - k + 1, 0);
        best = n - k;
        for (int i = n - k; i >= 0; i--) {
            if (w[i] >= w[best]) best = i;
            right[i] = best;
        }
        vector<int> result(3, 0);
        int maxSum = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            int l = left[i - k], r = right[i + k];
            int total = w[l] + w[i] + w[r];
            if (total > maxSum) {
                maxSum = total;
                result = {l, i, r};
            }
        }
        return result;
    }
};