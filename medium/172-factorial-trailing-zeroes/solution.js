/**
 * Factorial Trailing Zeroes
 * Time: O(log n) | Space: O(1)
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
    let count = 0;
    
    while (n >= 5) {
        n = Math.floor(n / 5);
        count += n;
    }
    
    return count;
};
