class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
    bool dfs(vector<double>& nums) {
        if (nums.size() == 1) return fabs(nums[0] - 24.0) < 1e-6;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                vector<double> next;
                for (int k = 0; k < n; k++)
                    if (k != i && k != j) next.push_back(nums[k]);
                for (int op = 0; op < 4; op++) {
                    if (op == 0) next.push_back(nums[i] + nums[j]);
                    else if (op == 1) next.push_back(nums[i] - nums[j]);
                    else if (op == 2) next.push_back(nums[i] * nums[j]);
                    else {
                        if (fabs(nums[j]) < 1e-6) continue;
                        next.push_back(nums[i] / nums[j]);
                    }
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};