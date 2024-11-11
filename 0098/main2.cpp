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
private:
    struct Interger {
        int v;
        bool isNull;
    };

public:
    bool isValidBST(TreeNode* root) {
        Interger last;
        last.v = 0;
        last.isNull = true;

        return dfs(root, last);
    }

    bool dfs(TreeNode* root, Interger& last) {
        
        if( root->left != nullptr ) {
            bool ok = dfs(root->left, last);
            if(!ok) return false;
        }

        
        if( !last.isNull && root->val <= last.v ) {
            return false;
        }
        last.v = root->val;
        last.isNull = false;

        if( root->right != nullptr ) {
            bool ok = dfs(root->right, last);
            if(!ok) return false;
        }

        return true;
    }
};
