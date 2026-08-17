class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        vector<int> parent(n * 2);
        for (int i = 0; i < n * 2; i++) parent[i] = i;
        function<int(int)> find = [&](int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); };
        auto unite = [&](int x, int y) { parent[find(x)] = find(y); };
        for (int i = 0; i < n; i++) {
            unite(i * 2, i * 2 + 1);
            unite(row[i * 2], row[i * 2 + 1]);
        }
        unordered_map<int, int> comp;
        for (int i = 0; i < n * 2; i++) comp[find(i)]++;
        int swaps = 0;
        for (auto& [k, v] : comp) swaps += v / 2 - 1;
        return swaps;
    }
};