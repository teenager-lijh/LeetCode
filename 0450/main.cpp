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
// 删除二叉树中的节点
// 使用该节点的左子树的最大值节点将其代替
// 或者使用该节点的右子树的最小值节点将其代替
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if( root == nullptr ) {
            return nullptr;
        }

        // 返回删除 指定节点后的 二分搜索树的根节点
        if( root->val != key ) {
            if( key < root->val && root->left != nullptr ) {
                root->left = deleteNode(root->left, key);
            } else if( key > root->val && root->right != nullptr ) {
                root->right = deleteNode(root->right, key);
            }

            return root;
        }

        // root->Val == key
        if( root->left == nullptr ) {
            return root->right;
        }

        if( root->right == nullptr ) {
            return root->left;
        }

        // left != null && right != null
        TreeNode* maxNode = deleteMaxNode(root->left, root, false);
        maxNode->left = root->left;
        maxNode->right = root->right;
        return maxNode;
    }

    TreeNode* deleteMaxNode(TreeNode* root, TreeNode* parent, bool isRight) {
        // 返回被删除的最大值节点
        if(root->right == nullptr ) {
            if(isRight) {
                parent->right = root->left;
            } else {
                parent->left = root->left;
            }

            return root;
        }

        return deleteMaxNode(root->right, root, true);
    }
};
