class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0) { x = 1 / x; n = -n; }
        double result = 1.0;
        while (n > 0) {
            if (n & 1) result *= x;
            x *= x;
            n >>= 1;
        }
        return result;
    }
};
