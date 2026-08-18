/**
 * Largest Number
 * Time: O(n log n) | Space: O(n)
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    const strs = nums.map(String);
    
    strs.sort((a, b) => (b + a).localeCompare(a + b));
    
    const result = strs.join('');
    
    return result[0] === '0' ? '0' : result;
};
