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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if( root == nullptr ) {
            return res;
        }

        queue<TreeNode*> q;

        int nums = 1;
        int level = 0;
        q.push(root);
        res.push_back(vector<int>());

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            res[level].push_back(node->val);
            nums --;

            if(node->left != nullptr) {
                q.push(node->left);
            }

            if(node->right != nullptr) {
                q.push(node->right);
            }

            if( nums <= 0 && !q.empty() ) {
                nums = q.size();
                level += 1;
                res.push_back(vector<int>());
            }
        }

        vector<vector<int>> result;
        for(auto iter = res.rbegin() ; iter != res.rend() ; iter++) {
            result.push_back(*iter);
        }

        return result;
    }
};
