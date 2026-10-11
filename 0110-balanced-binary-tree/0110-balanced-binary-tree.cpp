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
    int solve(TreeNode* node, int& diff) {
        if(!node) {
            return 0;
        }

        int left = 1 + solve(node->left, diff);
        int right = 1 + solve(node->right, diff);

        diff = max(diff, abs(left - right));

        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        int diff = 0;

        solve(root, diff);

        return diff < 2;
    }
};