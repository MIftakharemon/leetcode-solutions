class Solution {
public:
    int residuePrefixes(string s) {
        int count = 0;
        unordered_set<char> seen;
        for (int i = 0; i < s.size(); i++) {
            seen.insert(s[i]);
            if ((int)seen.size() == (i + 1) % 3) {
                count++;
            }
        }
        return count;
    }
};