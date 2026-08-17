/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    let result = 0;
    for (const c of s + t) result ^= c.charCodeAt(0);
    return String.fromCharCode(result);
};