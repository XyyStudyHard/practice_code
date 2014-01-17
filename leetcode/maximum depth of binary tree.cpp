/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int right = maxDepth(root->right);
        int left = maxDepth(root->left);
        if (right > left)
            return right + 1;
        else
            return left + 1;
    }
};