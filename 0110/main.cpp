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
// 判断是否是平衡二叉树
class Solution {
public:

    struct Info {
        bool isBalanced;
        int depth;

        Info(bool isBalanced, int depth) {
            this->isBalanced = isBalanced;
            this->depth = depth;
        }
    };

    bool isBalanced(TreeNode* root) {
        Info res = isBalancedTree(root);

        return res.isBalanced;
    }

    Info isBalancedTree(TreeNode* root) {
        if( root == nullptr ) {
            return Info(true, 0);
        }

        Info ld = isBalancedTree(root->left);
        Info rd = isBalancedTree(root->right);

        Info res = Info(
            (abs(ld.depth - rd.depth) <= 1) && ld.isBalanced && rd.isBalanced,
            max(ld.depth, rd.depth) + 1
        );

        return res;
    }
};
