class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        function<void(int)> dfs = [&](int start) {
            result.push_back(path);
            for (int i = start; i < nums.size(); i++) {
                path.push_back(nums[i]);
                dfs(i + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return result;
    }
};
