class Solution {
    string helper(int num) {
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                               "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                               "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        if (num >= 100) { res += ones[num / 100] + " Hundred"; num %= 100; }
        if (num >= 20) { if (!res.empty()) res += " "; res += tens[num / 10]; num %= 10; }
        if (num >= 10) { if (!res.empty()) res += " "; res += ones[num]; return res; }
        if (num > 0) { if (!res.empty()) res += " "; res += ones[num]; }
        return res;
    }
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res;
        vector<string> units = {"", "Thousand", "Million", "Billion"};
        for (int i = 0; num > 0; num /= 1000, i++) {
            int chunk = num % 1000;
            if (chunk > 0) {
                string part = helper(chunk);
                if (!res.empty()) res = part + " " + units[i] + " " + res;
                else res = part + " " + units[i];
            }
        }
        while (res.back() == ' ') res.pop_back();
        return res;
    }
};