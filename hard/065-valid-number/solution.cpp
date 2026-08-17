class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        
        // Skip optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        
        if (i == n) return false;
        
        bool hasDigit = false;
        bool hasDot = false;
        bool hasE = false;
        
        // Part before exponent
        while (i < n && s[i] != 'e' && s[i] != 'E') {
            if (s[i] == '.') {
                if (hasDot) return false;
                hasDot = true;
            } else if (isdigit(s[i])) {
                hasDigit = true;
            } else {
                return false;
            }
            i++;
        }
        
        if (!hasDigit) return false;
        
        // Check for exponent
        if (i < n) {
            hasE = true;
            i++;
            if (i == n) return false;
            
            // Optional sign after e/E
            if (s[i] == '+' || s[i] == '-') i++;
            
            if (i == n) return false;
            
            bool hasExpDigit = false;
            while (i < n) {
                if (!isdigit(s[i])) return false;
                hasExpDigit = true;
                i++;
            }
            if (!hasExpDigit) return false;
        }
        
        return true;
    }
};