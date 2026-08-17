/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    const rows = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm'];
    return words.filter(word => {
        const lower = word.toLowerCase();
        return rows.some(row => lower.split('').every(c => row.includes(c)));
    });
};