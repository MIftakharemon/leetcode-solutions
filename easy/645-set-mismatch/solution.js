/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findErrorNums = function(nums) {
    const set = new Set(nums);
    const sum = nums.reduce((a, b) => a + b, 0);
    const uniqueSum = [...set].reduce((a, b) => a + b, 0);
    const duplicate = sum - uniqueSum;
    const expected = nums.length * (nums.length + 1) / 2;
    return [duplicate, expected - uniqueSum];
};