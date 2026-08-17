/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
var selfDividingNumbers = function(left, right) {
    const result = [];
    for (let num = left; num <= right; num++) {
        const s = String(num);
        if (s.split('').every(d => d !== '0' && num % parseInt(d) === 0)) {
            result.push(num);
        }
    }
    return result;
};