class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            stack<int> stk;
            for (int j = 0; j <= n; j++) {
                int h = (j == n) ? 0 : heights[j];
                while (!stk.empty() && h < heights[stk.top()]) {
                    int height = heights[stk.top()]; stk.pop();
                    int width = stk.empty() ? j : j - stk.top() - 1;
                    maxArea = max(maxArea, height * width);
                }
                stk.push(j);
            }
        }
        return maxArea;
    }
};