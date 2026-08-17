class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            string next;
            for (int j = 0; j < s.size(); j++) {
                int cnt = 1;
                while (j + 1 < s.size() && s[j] == s[j + 1]) { j++; cnt++; }
                next += to_string(cnt) + s[j];
            }
            s = next;
        }
        return s;
    }
};
