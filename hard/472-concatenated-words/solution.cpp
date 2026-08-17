class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size() || (a.size() == b.size() && a < b);
        });
        unordered_set<string> dict;
        vector<string> result;
        for (string& word : words) {
            int n = word.size();
            if (n == 0) continue;
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j] && dict.count(word.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[n]) result.push_back(word);
            dict.insert(word);
        }
        return result;
    }
};