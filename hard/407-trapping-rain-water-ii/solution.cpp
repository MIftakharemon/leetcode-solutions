class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = visited[m - 1][j] = true;
        }
        int water = 0, maxH = 0;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            int h = cell[0], r = cell[1], c = cell[2];
            maxH = max(maxH, h);
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    water += max(0, maxH - heightMap[nr][nc]);
                    pq.push({max(heightMap[nr][nc], maxH), nr, nc});
                }
            }
        }
        return water;
    }
};