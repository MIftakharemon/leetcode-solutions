class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1);
        int maxLen = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            start = max(start, last[s[i]] + 1);
            maxLen = max(maxLen, i - start + 1);
            last[s[i]] = i;
        }
        return maxLen;
    }
};