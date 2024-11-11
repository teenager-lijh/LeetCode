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
    int sumOfLeftLeaves(TreeNode* root) {
        if( root == nullptr ) {
            return 0;
        }

        if( root->left == nullptr && root->right == nullptr ) {
            return 0;
        }

        return calculateSumOfLeftLeaves(root, false);
    }

    int calculateSumOfLeftLeaves(TreeNode* root, bool isLeft) {
        if( root->left == nullptr && root->right == nullptr ) {
            if( isLeft ) {
                return root->val;
            } else {
                return 0;
            }
        }

        int ls = 0;
        int rs = 0;

        if( root->left != nullptr ) {
            ls = calculateSumOfLeftLeaves(root->left, true);
        }

        if( root->right != nullptr ) {
            rs = calculateSumOfLeftLeaves(root->right, false);
        }

        return ls + rs;
    }
};
