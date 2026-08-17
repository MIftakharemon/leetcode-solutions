class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int lRem = 0, rRem = 0;
        for (char c : s) {
            if (c == '(') lRem++;
            else if (c == ')') {
                if (lRem > 0) lRem--;
                else rRem++;
            }
        }
        function<void(int, int, int, string)> dfs = [&](int i, int lRem, int rRem, string path) {
            if (i == s.size()) {
                if (lRem == 0 && rRem == 0) result.insert(path);
                return;
            }
            char c = s[i];
            if (c != '(' && c != ')') {
                dfs(i + 1, lRem, rRem, path + c);
            } else {
                if (c == '(') {
                    if (lRem > 0) dfs(i + 1, lRem - 1, rRem, path);
                    dfs(i + 1, lRem, rRem, path + c);
                } else {
                    if (rRem > 0) dfs(i + 1, lRem, rRem - 1, path);
                    int open = 0;
                    for (char ch : path) {
                        if (ch == '(') open++;
                        else if (ch == ')') open--;
                    }
                    if (open > 0) dfs(i + 1, lRem, rRem, path + c);
                }
            }
        };
        dfs(0, lRem, rRem, "");
        return vector<string>(result.begin(), result.end());
    }
};