class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string dir;
        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (dir == "..") { if (!st.empty()) st.pop_back(); }
                else if (!dir.empty() && dir != ".") st.push_back(dir);
                dir.clear();
            } else {
                dir += path[i];
            }
        }
        string result;
        for (string& s : st) result += "/" + s;
        return result.empty() ? "/" : result;
    }
};
