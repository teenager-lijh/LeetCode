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


// 1 暴力解法
class Solution {
public:
    int res = 0;
    int sum = 0;

    int findTargetSumWays(vector<int>& nums, int target) {
        backTrace(nums, 0, target);

        return res;
    }

    //
    void backTrace(vector<int>& nums, int i, int target){
        if(i >= nums.size()) {
            if(sum == target)
                res += 1;

            return;
        }

        // 做选择 加上 nums[i]
        sum += nums[i];
        backTrace(nums, i+1, target);
        // 撤销选择
        sum -= nums[i];

        // 做选择 减去 nums[i]
        sum -= nums[i];
        backTrace(nums, i+1, target);
        // 撤销选择
        sum += nums[i];
    }
};


int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    int res = Solution().findTargetSumWays(nums, target);

    cout << "res : " << res;

    return 0;
}