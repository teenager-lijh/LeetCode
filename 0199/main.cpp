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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if( root == nullptr ) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        int nums = q.size();
        int level = 0;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left != nullptr) {
                q.push(node->left);
            }

            if(node->right != nullptr) {
                q.push(node->right);
            }

            if( --nums <= 0 ) {
                res.push_back(node->val);
                nums = q.size();
                level += 1;
            }
        }

        return res;
    }
};
