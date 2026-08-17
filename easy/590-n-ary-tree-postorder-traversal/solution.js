/**
 * // Definition for a Node.
 * function Node(val, children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number[]}
 */
var postorder = function(root) {
    const result = [];
    const dfs = (node) => {
        if (!node) return;
        for (const child of node.children) dfs(child);
        result.push(node.val);
    };
    dfs(root);
    return result;
};