class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for (char ch : s) {
            if (isalpha(ch)) {
                if (string("aeiou").find(ch) != string::npos) v++;
                else c++;
            }
        }
        return c > 0 ? v / c : 0;
    }
};