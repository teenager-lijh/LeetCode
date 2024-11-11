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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, nullptr, true, 0, nums.size()-1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, TreeNode* parent, bool isLeft, int l, int r) {
        // 根据 nums[l...r] 创建当前节点并返回
        
        if( l > r ) {
            return nullptr;
        }

        int mid = (l + r) / 2;
        int v = nums[mid];

        TreeNode* cur = new TreeNode(v, nullptr, nullptr);

        if( parent != nullptr && isLeft ) {
            parent->left = cur;
        } else if( parent != nullptr && !isLeft ) {
            parent->right = cur;
        }

        sortedArrayToBST(nums, cur, true, l, mid-1);
        sortedArrayToBST(nums, cur, false, mid+1, r);

        return cur;
    }
};
