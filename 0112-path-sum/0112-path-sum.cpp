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
    bool solve(TreeNode* root, int targetSum) {
        if(!root) {
            cout<<targetSum<<endl;
            if(targetSum == 0) return true;
            return false;
        }

        bool left = solve(root->left, targetSum - root->val);
        bool right = solve(root->right, targetSum - root->val);

        if(!root->left) return right;
        if(!root->right) return left;

        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return solve(root, targetSum);
    }
};