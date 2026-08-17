class Solution {
public:
    bool rows[9][9] = {}, cols[9][9] = {}, boxes[9][9] = {};
    bool solve(vector<vector<char>>& board, int r, int c) {
        if (r == 9) return true;
        if (c == 9) return solve(board, r + 1, 0);
        if (board[r][c] != '.') return solve(board, r, c + 1);
        for (int d = 0; d < 9; d++) {
            int b = (r / 3) * 3 + c / 3;
            if (!rows[r][d] && !cols[c][d] && !boxes[b][d]) {
                board[r][c] = '1' + d;
                rows[r][d] = cols[c][d] = boxes[b][d] = true;
                if (solve(board, r, c + 1)) return true;
                board[r][c] = '.';
                rows[r][d] = cols[c][d] = boxes[b][d] = false;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int d = board[i][j] - '1';
                    int b = (i / 3) * 3 + j / 3;
                    rows[i][d] = cols[j][d] = boxes[b][d] = true;
                }
        solve(board, 0, 0);
    }
};