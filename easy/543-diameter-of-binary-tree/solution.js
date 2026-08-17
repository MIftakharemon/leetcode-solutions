/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
    let max = 0;
    const depth = (node) => {
        if (!node) return 0;
        const left = depth(node.left);
        const right = depth(node.right);
        max = Math.max(max, left + right);
        return Math.max(left, right) + 1;
    };
    depth(root);
    return max;
};