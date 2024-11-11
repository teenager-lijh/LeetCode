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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;

        if(root == nullptr) {
            return res;
        }

        res.push_back(vector<int>());

        q.push(root);
        int nums = 1;
        int i = 0;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            nums --;
            res[i].push_back(node->val);

            if(node->left != nullptr) {
                q.push(node->left);
            }

            if(node->right != nullptr) {
                q.push(node->right);
            }

            if( nums <= 0 ) {
                nums = q.size();
                i += 1;
                if(nums > 0) {
                    res.push_back(vector<int>());
                }
            }
        }

        return res;
    }
};
