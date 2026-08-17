class MyCalendarThree {
public:
    map<int, int> diff;
    MyCalendarThree() {}
    int book(int start, int end) {
        diff[start]++;
        diff[end]--;
        int maxOverlap = 0, cur = 0;
        for (auto& [k, v] : diff) {
            cur += v;
            maxOverlap = max(maxOverlap, cur);
        }
        return maxOverlap;
    }
};