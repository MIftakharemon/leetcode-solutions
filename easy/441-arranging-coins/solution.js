/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) {
    let left = 1, right = n;
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        const total = Math.floor(mid * (mid + 1) / 2);
        if (total === n) return mid;
        else if (total < n) left = mid + 1;
        else right = mid - 1;
    }
    return right;
};