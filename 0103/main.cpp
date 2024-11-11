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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if( root == nullptr) {
            return res;
        }

        int level = 0;
        int nums = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(level == res.size()) {
                res.push_back(vector<int>());
            }

            res[level].push_back(node->val);

            if(node->left != nullptr) {
                q.push(node->left);
            }

            if(node->right != nullptr) {
                q.push(node->right);
            }

            if( --nums <= 0 ) {
                level += 1;
                nums = q.size();
            }
        }

        for( int i = 0 ; i < res.size() ; i++ ) {
            if( i%2 != 0 ) {
                // 翻转 vector
                int sz = res[i].size() / 2;
                for( int j = 0 ; j < sz ; j++ ) {
                    swap(res[i][j], res[i][res[i].size()-1-j]);
                }
            }
        }

        return res;
    }
};
