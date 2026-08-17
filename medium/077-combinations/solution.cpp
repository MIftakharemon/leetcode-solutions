class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        function<void(int)> dfs = [&](int start) {
            if (path.size() == k) { result.push_back(path); return; }
            for (int i = start; i <= n; i++) {
                path.push_back(i);
                dfs(i + 1);
                path.pop_back();
            }
        };
        dfs(1);
        return result;
    }
};
