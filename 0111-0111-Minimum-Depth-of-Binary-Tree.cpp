#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution {
public:
    int minDepth(TreeNode* root) {
        // 若根节点不存在则 depth 为 0 
        // 直接返回 0 即可
        if(root == nullptr) return 0;
        
        queue<TreeNode*> q;
        q.push(root);

        // depth 存储的是当前正在遍历的
        // 那一层的深度
        // 因为首先遍历的是根节点
        // 则 depth 应初始化为 1
        int depth = 1;
        while(!q.empty()) {
            // 在还没有开始遍历一层的时候
            // 队列 q 中存储了即将遍历的那一层的节点
            // 所以 q.size() 就是即将遍历的这一层的节点数量
            // 记录当前层的节点个数 sz
            int sz = q.size();
            
            
            // 一次 for 循环的完整执行
            // 就是完成了二叉树的一层的遍历
            for(int i = 0; i < sz; ++i){
                TreeNode* cur = q.front();
                q.pop();

                // 目标是找到第一个层次遍历中
                // 所遇到的那个叶子节点
                // 此时直接返回 depth
                if(cur->left == nullptr && cur->right == nullptr)
                    return depth;


                // 添加 cur 的相邻节点到队列中
                // 对于二叉树而言就是添加其不为空的孩子节点
                if(cur->left != nullptr)
                    q.push(cur->left);
                if(cur->right != nullptr)
                    q.push(cur->right);
            }

            // 此时完成了整个的 for 循环
            // 维护 depth 变量的定义
            // 继续遍历下一层的节点
            depth += 1;
        }

        // 对于这个题目来说
        // 它并不会执行
        // 因为一定可以在 while 循环中找到叶子节点
        // 但我不这么写， LeetCode 编译出错
        // 说存在没有返回值的情况
        return depth-1;
    }
};


int main() {
    cout << "0111" << endl;

    Solution solution;


    cout << "end" << endl;

}