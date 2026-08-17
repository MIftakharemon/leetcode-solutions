/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;
    int maxGain(TreeNode* node) {
        if (!node) return 0;
        int left = max(0, maxGain(node->left));
        int right = max(0, maxGain(node->right));
        maxSum = max(maxSum, node->val + left + right);
        return node->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};