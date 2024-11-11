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

    void postorder(TreeNode* node, vector<int>& vec) {
        if( node == nullptr ) {
            return;
        }

        postorder(node->left, vec);
        postorder(node->right, vec);
        vec.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        postorder(root, res);

        return res;
    }
};
