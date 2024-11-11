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
    bool isValidBST(TreeNode* root) {
        vector<int> values;

        return dfs(root, values);
    }

    bool dfs(TreeNode* root, vector<int>& values) {
        
        if( root->left != nullptr ) {
            bool ok = dfs(root->left, values);
            if(!ok) return false;
        }

        values.push_back( root->val );
        if( values.size() >= 2 && root->val <= values[values.size()-2] ) {
            return false;
        }

        if( root->right != nullptr ) {
            bool ok = dfs(root->right, values);
            if(!ok) return false;
        }

        return true;
    }
};
