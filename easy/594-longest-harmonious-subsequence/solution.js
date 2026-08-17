/**
 * @param {number[]} nums
 * @return {number}
 */
var findLHS = function(nums) {
    const count = {};
    for (const num of nums) count[num] = (count[num] || 0) + 1;
    let max = 0;
    for (const num in count) {
        if (count[Number(num) + 1]) {
            max = Math.max(max, count[num] + count[Number(num) + 1]);
        }
    }
    return max;
};