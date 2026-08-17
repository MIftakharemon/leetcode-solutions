class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for (int i = 2; i <= n; i++) {
            vector<int> ndp(k + 1, 0);
            vector<long long> prefix(k + 2, 0);
            for (int j = 0; j <= k; j++) {
                prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
            }
            for (int j = 0; j <= k; j++) {
                int maxAdd = min(j, i - 1);
                ndp[j] = (prefix[j + 1] - prefix[j + 1 - maxAdd - 1] + MOD) % MOD;
            }
            dp = ndp;
        }
        return dp[k];
    }
};