class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        long long A0L0 = 1, A0L1 = 0, A0L2 = 0, A1L0 = 0, A1L1 = 0, A1L2 = 0;
        for (int i = 0; i < n; i++) {
            long long nA0L0 = (A0L0 + A0L1 + A0L2) % MOD;
            long long nA0L1 = A0L0;
            long long nA0L2 = A0L1;
            long long nA1L0 = (A1L0 + A1L1 + A1L2 + A0L0 + A0L1 + A0L2) % MOD;
            long long nA1L1 = A1L0;
            long long nA1L2 = A1L1;
            A0L0 = nA0L0; A0L1 = nA0L1; A0L2 = nA0L2;
            A1L0 = nA1L0; A1L1 = nA1L1; A1L2 = nA1L2;
        }
        return (A0L0 + A0L1 + A0L2 + A1L0 + A1L1 + A1L2) % MOD;
    }
};