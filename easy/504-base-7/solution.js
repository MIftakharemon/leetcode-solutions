/**
 * @param {number} num
 * @return {string}
 */
var convertToBase7 = function(num) {
    if (num === 0) return '0';
    let result = '', n = Math.abs(num);
    while (n > 0) {
        result = (n % 7) + result;
        n = Math.floor(n / 7);
    }
    return num < 0 ? '-' + result : result;
};