/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == nullptr || p == nullptr || q == nullptr ) {
            return nullptr;
        }

        // 若当前节点不是同时大于 p.val 或者 q.val 则当前节点就是他俩的最近公共祖先
        if( !(p->val > root->val && q->val > root->val) && 
            !(p->val < root->val && q->val < root->val) ) {
            return root;
        }

        // 查找左子树的情况
        if( p->val < root->val && q->val < root->val && root->left != nullptr ) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // 查找右子树的情况
        if( p->val > root->val && q->val > root->val && root->right != nullptr ) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // 这个情况不可能发生
        return nullptr;
    }
};
