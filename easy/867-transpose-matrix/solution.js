/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var transpose = function(matrix) {
    const m = matrix.length, n = matrix[0].length;
    const result = Array.from({length: n}, () => new Array(m));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
};