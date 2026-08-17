/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    let i = num1.length - 1, j = num2.length - 1, carry = 0, result = '';
    while (i >= 0 || j >= 0 || carry) {
        const a = i >= 0 ? parseInt(num1[i--]) : 0;
        const b = j >= 0 ? parseInt(num2[j--]) : 0;
        const sum = a + b + carry;
        result = (sum % 10) + result;
        carry = Math.floor(sum / 10);
    }
    return result;
};