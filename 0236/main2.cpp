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

private:
struct Value {
    bool p;
    bool q;
    TreeNode* ancestor;

    Value(TreeNode* p, TreeNode* q, TreeNode* ancestor) : p(p), q(q), ancestor(ancestor) {}
};

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Value value = Ancestor(root, p, q);
        return value.ancestor;
    }

    Value Ancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Value value(nullptr, nullptr, nullptr);

        if( root == p ) {
            value.p = true;
        }

        if( root == q ) {
            value.q = true;
        }

        if( value.p && value.q ) {
            value.ancestor = root;
            return value;
        }

        if( root->left != nullptr ) {
            Value temp = Ancestor(root->left, p, q);
            if( temp.ancestor != nullptr ) {
                return temp;
            }

            if( temp.p ) value.p = temp.p;
            if( temp.q ) value.q = temp.q;
        }

        if( root->right != nullptr ) {
            Value temp = Ancestor(root->right, p, q);
            if( temp.ancestor != nullptr ) {
                return temp;
            }

            if( temp.p ) value.p = temp.p;
            if( temp.q ) value.q = temp.q;
        }

        if( value.p && value.q ) {
            value.ancestor = root;
            return value;
        }

        return value;
    }
};
