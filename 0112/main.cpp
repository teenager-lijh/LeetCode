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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if( root == nullptr ) return false;

        return binarySearch(root, 0, targetSum);
    }

    bool binarySearch(TreeNode* root, int cur, int targetSum) {

        if( root == nullptr ) {
            return false;
        }

        if( root->left == nullptr && root->right == nullptr ) {
            return (cur+root->val) == targetSum;
        }

        return binarySearch(root->left, cur+root->val, targetSum) || binarySearch(root->right, cur+root->val, targetSum);
    }
};
