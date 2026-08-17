/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} ops
 * @return {number}
 */
var maxCount = function(m, n, ops) {
    let minR = m, minC = n;
    for (const [r, c] of ops) {
        minR = Math.min(minR, r);
        minC = Math.min(minC, c);
    }
    return minR * minC;
};