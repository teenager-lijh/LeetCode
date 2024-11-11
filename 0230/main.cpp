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
    int kthSmallest(TreeNode* root, int k) {
        int counter = k;
        return kthSmallestValue(root, counter);
    }

    int kthSmallestValue(TreeNode* root, int& counter) {

        if( root->left != nullptr ) {
            int v = kthSmallestValue(root->left, counter);
            if( counter <= 0 ) return v;
        }

        if( --counter <= 0 ) {
            return root->val;
        }

        if( root->right != nullptr ) {
            int v = kthSmallestValue(root->right, counter);
            if( counter <= 0 ) return v;
        }

        return -1;
    }
};
