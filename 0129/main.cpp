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
    struct Value {
        int v;
        int coef;

        Value(int v, int coef) : v(v), coef(coef) {}
    };


public:
    int sumNumbers(TreeNode* root) {
        if( root == nullptr ) {
            return 0;
        }

        int res = 0;
        vector<Value> temp = searchNumbers(root);
        for( int i = 0 ; i < temp.size() ; i++ ) res += temp[i].v;

        return res;
    }

    vector<Value> searchNumbers(TreeNode* root) {
        vector<Value> res;

        if( root->left == nullptr && root->right == nullptr ) {
            res.push_back(Value(root->val, 1));
        }

        if( root->left != nullptr ) {
            vector<Value> temp = searchNumbers(root->left);
            for( int i = 0 ; i < temp.size() ; i++ ) {
                int coef = temp[i].coef * 10;
                int v = temp[i].v + root->val * coef;
                res.push_back(Value(v, coef));
            }
        }


        if( root->right != nullptr ) {
            vector<Value> temp = searchNumbers(root->right);
            for( int i = 0 ; i < temp.size() ; i++ ) {
                int coef = temp[i].coef * 10;
                int v = temp[i].v + root->val * coef;
                res.push_back(Value(v, coef));
            }
        }

        return res;
    }
};
