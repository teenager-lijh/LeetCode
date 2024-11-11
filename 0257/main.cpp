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
    vector<string> binaryTreePaths(TreeNode* root) {
        if( root == nullptr ) {
            return vector<string>();
        }

        vector<string> record;

        if(root->left == nullptr && root->right == nullptr) {
            record.push_back(to_string(root->val));
        }

        if(root->left != nullptr) {
            vector<string> leftRecord = binaryTreePaths(root->left);
            for( int i = 0 ; i < leftRecord.size() ; i++ ) {
                record.push_back(to_string(root->val) + "->" + leftRecord[i]);
            }
        }

        if(root->right != nullptr) {
            vector<string> rightRecord = binaryTreePaths(root->right);
            for( int i = 0 ; i < rightRecord.size() ; i++ ) {
                record.push_back(to_string(root->val) + "->" + rightRecord[i]);
            }
        }

        return record;
    }
};
