class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        long long total = 0;
        for (auto& c : courses) {
            if (total + c[0] <= c[1]) {
                pq.push(c[0]);
                total += c[0];
            } else if (!pq.empty() && pq.top() > c[0]) {
                total -= pq.top() - c[0];
                pq.pop();
                pq.push(c[0]);
            }
        }
        return pq.size();
    }
};