class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0, n = words.size();
        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;
            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }
            int wordCount = j - i;
            int spaces = maxWidth - lineLen + (wordCount - 1);
            string line = "";
            if (j == n || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                while (line.size() < maxWidth) line += " ";
            } else {
                int spaceEach = spaces / (wordCount - 1);
                int extra = spaces % (wordCount - 1);
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToAdd = spaceEach + (k - i < extra ? 1 : 0);
                        line += string(spacesToAdd, ' ');
                    }
                }
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};