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
    TreeNode* createTree(int left, int right, vector<int>& nums) {
        if(left > right) return NULL;

        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode();

        node->val = nums[mid];
        node->left = createTree(left, mid-1, nums);
        node->right = createTree(mid+1, right, nums);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();

        TreeNode* root = new TreeNode();
        root->val = nums[n/2];

        TreeNode* left = createTree(0, n/2 - 1, nums);
        TreeNode* right = createTree(n/2 + 1, n - 1, nums);

        root->left = left;
        root->right = right;

        return root;
    }
};