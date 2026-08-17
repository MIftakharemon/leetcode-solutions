class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string word = q.front(); q.pop();
                for (int j = 0; j < word.size(); j++) {
                    char orig = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        if (word == endWord) return level + 1;
                        if (wordSet.count(word)) {
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }
                    word[j] = orig;
                }
            }
            level++;
        }
        return 0;
    }
};