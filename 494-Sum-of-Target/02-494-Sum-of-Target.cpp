//
// Created by 李嘉豪 on 2022/9/26.
//
#include <iostream>
#include <vector>
using namespace  std;


//示例 1：
//
//输入：nums = [1,1,1,1,1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//-1 + 1 + 1 + 1 + 1 = 3
//+1 - 1 + 1 + 1 + 1 = 3
//+1 + 1 - 1 + 1 + 1 = 3
//+1 + 1 + 1 - 1 + 1 = 3
//+1 + 1 + 1 + 1 - 1 = 3

// 背包的解决思路

// 2 动态规划
class Solution {
public:

//    sum(A) = (target + sum(nums)) / 2

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for(int each : nums)
            sum += each;

        // 所有的元素均是大于 0 的
        // 当把所有元素累加后应该 小于 target
        // 或 把所有元素累加后应该 小于 -target (target 可为负) 就是所有元素都取负号累加的情况
        if((target + sum) % 2 == 1 || sum < target || sum < -target) return 0;

        int C = (target + sum) / 2;
        int dp[nums.size()][C+1];


        // 处理第 0 号行
        for(int j = 0 ; j <= C ; ++j)
            dp[0][j] = 0;

        dp[0][0] = 1; // 不装入 0 号元素是一种装法
        if(nums[0] <= C) dp[0][nums[0]] += 1; // 装入 0 号元素是一种装法

        for(int i = 1 ; i < nums.size() ; ++i){
            for(int j = 0 ; j <= C ; ++j){
                // 当装不进去 nums[i] 时
                if(j - nums[i] < 0){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    // 当可以装进去 nums[i] 时
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
                }
            }
        }

        return dp[nums.size()-1][C];
    }
};


int main()
{
//    vector<int> nums = {1, 1, 1, 1, 1};
//    int target = 3;

    vector<int> nums = {100};
    int target = -200;

    int res = Solution().findTargetSumWays(nums, target);

    cout << "res : " << res;

    return 0;
}