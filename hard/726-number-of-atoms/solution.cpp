class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> count;
        stack<map<string, int>> st;
        int n = formula.size(), i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push({});
                i++;
            } else if (formula[i] == ')') {
                i++;
                int num = 0;
                while (i < n && isdigit(formula[i])) num = num * 10 + formula[i++] - '0';
                num = max(num, 1);
                auto top = st.top(); st.pop();
                if (st.empty()) {
                    for (auto& [k, v] : top) count[k] += v * num;
                } else {
                    for (auto& [k, v] : top) st.top()[k] += v * num;
                }
            } else if (isupper(formula[i])) {
                string elem;
                elem += formula[i++];
                while (i < n && islower(formula[i])) elem += formula[i++];
                int num = 0;
                while (i < n && isdigit(formula[i])) num = num * 10 + formula[i++] - '0';
                num = max(num, 1);
                if (st.empty()) count[elem] += num;
                else st.top()[elem] += num;
            } else {
                i++;
            }
        }
        string result;
        for (auto& [k, v] : count) {
            result += k;
            if (v > 1) result += to_string(v);
        }
        return result;
    }
};