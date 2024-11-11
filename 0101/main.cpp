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
// 二叉树的递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if( root == nullptr ) {
            return true;
        }

        return isSymmetricTree(root->left, root->right);
    }

    bool isSymmetricTree(TreeNode* left, TreeNode* right) {
        if( left == nullptr || right == nullptr ) {
            return left == right;
        }

        return left->val == right->val && isSymmetricTree(left->left, right->right) && isSymmetricTree(left->right, right->left);
    }
};
