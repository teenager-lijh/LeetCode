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
    const int maxNum = 1000000;
    int minDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        // 返回 root 的最小深度
        if(root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int lm = maxNum;
        int rm = maxNum;

        if(root->left != nullptr) lm = minDepth(root->left);
        if(root->right != nullptr) rm = minDepth(root->right);

        return min(lm, rm) + 1;
    }
};
