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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;

        if( root == nullptr ) {
            return res;
        }

        vector<vector<int>> paths = searchPath(root);

        for( int i = 0 ; i < paths.size() ; i++ ) {
            int s = 0;
            for( int j = 0 ; j < paths[i].size() ; j++ ) {
                s += paths[i][j];
            }
            if(s == targetSum) {
                res.push_back(paths[i]);
            }
        }

        return res;
    }

    vector<vector<int>> searchPath(TreeNode* root) {
        vector<vector<int>> res;

        if( root->left == nullptr && root->right == nullptr ) {
            res.push_back(vector<int>({root->val}));
        }

        if( root->left != nullptr ) {
            vector<vector<int>> lr = searchPath(root->left);
            for( int i = 0 ; i < lr.size() ; i++ ) {
                vector<int> temp;
                temp.push_back(root->val);
                temp.insert(temp.end(), lr[i].begin(), lr[i].end());
                res.push_back(temp);
            }
        }

        if( root->right != nullptr ) {
            vector<vector<int>> rr = searchPath(root->right);
            for( int i = 0 ; i < rr.size() ; i++ ) {
                vector<int> temp;
                temp.push_back(root->val);
                temp.insert(temp.end(), rr[i].begin(), rr[i].end());
                res.push_back(temp);
            }
        }

        return res;
    }
};
