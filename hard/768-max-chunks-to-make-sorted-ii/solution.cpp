class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        long long sum1 = 0, sum2 = 0;
        int chunks = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum1 += arr[i];
            sum2 += sorted_arr[i];
            if (sum1 == sum2) chunks++;
        }
        return chunks;
    }
};