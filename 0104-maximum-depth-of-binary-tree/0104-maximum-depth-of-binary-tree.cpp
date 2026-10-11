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
    int solve(int depth, TreeNode* root) {
        if(!root) {
            return depth;
        }

        int leftDepth = solve(depth+1, root->left);
        int rightDepth = solve(depth+1, root->right);

        return max(leftDepth, rightDepth);
    }
    int maxDepth(TreeNode* root) {
        return solve(0, root);
    }
};