/**
 * @param {number[][]} image
 * @return {number[][]}
 */
var flipAndInvertImage = function(image) {
    return image.map(row => row.reverse().map(x => x ^ 1));
};