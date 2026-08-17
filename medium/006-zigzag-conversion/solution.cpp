class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(min(numRows, (int)s.size()));
        int cur = 0, dir = -1;
        for (char c : s) {
            rows[cur] += c;
            if (cur == 0 || cur == numRows - 1) dir = -dir;
            cur += dir;
        }
        string result;
        for (string& row : rows) result += row;
        return result;
    }
};