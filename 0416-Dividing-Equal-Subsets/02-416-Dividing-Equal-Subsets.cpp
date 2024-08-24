//
// Created by 李嘉豪 on 2022/9/26.
//

#include <iostream>
#include <vector>
using namespace  std;

// 动态规划 + 状态压缩
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

        // 容量 [0...C]
        int dp[C+1];

        // 处理仅考虑 0 号元素的情况
        dp[0] = true; // 选择不装 0 号元素可装满
        for(int j = 1 ; j <= C ; ++j)
            dp[j] = false;
        // 该位置可装满
        if(nums[0] <= C) dp[nums[0]] = true;

        for(int i = 1 ; i < nums.size() ; ++i) {
            for(int j = C ; j >= 0 ; --j) {
                // 没办法装入 i 号元素的时候
                // dp[j] 的值不变
                if(j > nums[i]) {
                    dp[j] = dp[j] || dp[j-nums[i]];
                }
            }
        }

        return dp[C];
    }
};

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    bool res = Solution().canPartition(nums);
    cout << "res : " << res;
    return 0;
}