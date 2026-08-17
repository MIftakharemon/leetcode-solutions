class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int maxLen = 0;
        function<int(int, int)> dfs = [&](int i, int j) {
            if (memo[i][j]) return memo[i][j];
            int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                    memo[i][j] = max(memo[i][j], dfs(ni, nj));
                }
            }
            return ++memo[i][j];
        };
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                maxLen = max(maxLen, dfs(i, j));
        return maxLen;
    }
};