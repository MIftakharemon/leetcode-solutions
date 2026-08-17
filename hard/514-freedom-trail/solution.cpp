class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size(), n = key.size();
        unordered_map<char, vector<int>> pos;
        for (int i = 0; i < m; i++) pos[ring[i]].push_back(i);
        vector<vector<int>> memo(m, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int ri, int ki) -> int {
            if (ki == n) return 0;
            if (memo[ri][ki] != -1) return memo[ri][ki];
            int res = INT_MAX;
            for (int pi : pos[key[ki]]) {
                int diff = abs(ri - pi);
                int step = min(diff, m - diff);
                res = min(res, step + 1 + dfs(pi, ki + 1));
            }
            return memo[ri][ki] = res;
        };
        return dfs(0, 0);
    }
};