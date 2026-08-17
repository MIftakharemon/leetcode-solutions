/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function(s) {
    return s.split(' ').filter(seg => seg.length > 0).length;
};