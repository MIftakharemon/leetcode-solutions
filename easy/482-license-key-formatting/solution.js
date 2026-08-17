/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var licenseKeyFormatting = function(s, k) {
    const chars = s.replace(/-/g, '').toUpperCase();
    let result = '';
    for (let i = chars.length - 1, count = 0; i >= 0; i--) {
        if (count === k) {
            result = '-' + result;
            count = 0;
        }
        result = chars[i] + result;
        count++;
    }
    return result;
};