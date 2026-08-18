/**
 * House Robber
 * Time: O(n) | Space: O(1)
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if (nums.length === 1) return nums[0];
    
    let prev2 = 0;
    let prev1 = 0;
    
    for (const num of nums) {
        const temp = Math.max(prev1, prev2 + num);
        prev2 = prev1;
        prev1 = temp;
    }
    
    return prev1;
};
