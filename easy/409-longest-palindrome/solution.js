/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    const count = {};
    for (const c of s) count[c] = (count[c] || 0) + 1;
    let result = 0, hasOdd = false;
    for (const c in count) {
        result += Math.floor(count[c] / 2) * 2;
        if (count[c] % 2 === 1) hasOdd = true;
    }
    return hasOdd ? result + 1 : result;
};