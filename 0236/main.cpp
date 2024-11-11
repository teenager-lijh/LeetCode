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
    TreeNode* p;
    TreeNode* q;
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
            value.p = root;
        }

        if( root == q ) {
            value.q = root;
        }

        if( value.p != nullptr && value.q != nullptr ) {
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

        if( value.p != nullptr && value.q != nullptr ) {
            value.ancestor = root;
            return value;
        }

        return value;
    }
};
