//
// Created by 李嘉豪 on 2022/9/26.
//

#include <iostream>
#include <vector>
using namespace  std;

// 416 分割等和子集
// 可参考如下文章：
// https://mp.weixin.qq.com/s/OzdkF30p5BHelCi6inAnNg

// 动态规划解法
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;

        // sum 是奇数的时候是不可能分割的
        if(sum % 2 != 0) return false;

        // [0...nums.size()-1] 数值
        // [0...C] 容量
        int C = sum / 2;
        // dp[i][j] 考虑 [0...i] 数值且容量为 j 时能否装满
        bool dp[nums.size()][C+1];

        // 容量为 0 的时候都能装满 ==> 可以都不装
        for(int i = 0 ; i < nums.size() ; ++i)
            dp[i][0] = true;

        // 当容量 >= 1 的时候只有 dp[0][nums[0]] 能装满
        // 其他位置都装不满
        for(int j = 1 ; j <= C ; ++j)
            dp[0][j] = false;

        // dp[0][nums[0]] 能装满
        if(nums[0] <= C) dp[0][nums[0]] = true;


        for(int i = 1 ; i < nums.size() ; ++i) {
            for(int j = 1 ; j <= C ; ++j) {
                // 容量不足以装入 i 号元素
                // 先减去了第 i 号元素所需要的空间
                // 然后才去装其他的元素的
                if(nums[i] > j)
                    dp[i][j] = dp[i-1][j];
                else {
                    // 容量 j 能装入第 i 号元素
                    // 结果取 装入 i 号 或 不装入 i 号元素
                    // 两者中能够正好装满的那个结果
                    // 不装入 i 号元素的时候是 j-0
                    // 装入 i 号元素的时候是 j-nums[i]
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }


        return dp[nums.size()-1][C];
    }

};

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    bool res = Solution().canPartition(nums);
    cout << "res : " << res;
    return 0;
}