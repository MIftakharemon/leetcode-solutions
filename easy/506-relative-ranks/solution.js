/**
 * @param {number[]} score
 * @return {string[]}
 */
var findRelativeRanks = function(score) {
    const sorted = [...score].sort((a, b) => b - a);
    const map = {};
    sorted.forEach((s, i) => {
        if (i === 0) map[s] = 'Gold Medal';
        else if (i === 1) map[s] = 'Silver Medal';
        else if (i === 2) map[s] = 'Bronze Medal';
        else map[s] = String(i + 1);
    });
    return score.map(s => map[s]);
};