/**
 * @param {number} num
 * @return {string}
 */
var toHex = function(num) {
    if (num === 0) return '0';
    const hex = '0123456789abcdef';
    let result = '';
    for (let i = 0; i < 8; i++) {
        result = hex[num & 15] + result;
        num >>>= 4;
    }
    return result.replace(/^0+/, '');
};