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
 * @return {number[]}
 */
var findMode = function(root) {
    const count = {};
    const dfs = (node) => {
        if (!node) return;
        count[node.val] = (count[node.val] || 0) + 1;
        dfs(node.left);
        dfs(node.right);
    };
    dfs(root);
    const maxCount = Math.max(...Object.values(count));
    return Object.keys(count).filter(k => count[k] === maxCount).map(Number);
};