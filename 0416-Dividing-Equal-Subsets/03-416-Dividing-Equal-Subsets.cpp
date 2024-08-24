//
// Created by 李嘉豪 on 2022/9/27.
//

#include <iostream>
#include <vector>
using namespace  std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;

        if(sum % 2 != 0) return false;

        return backtrack(nums, 0, sum/2);
    }

    // 当前容量为 c
    // 选择 装或不装 第i号 数值后是否满足条件
    // 不满足则继续考察下一个数值
    bool backtrack(vector<int>& nums, int i, int c) {
        // 当容量 c = 0 的时候
        // 说明装满了，可以直接返回 true
        // 否则 若已经遍历了所有的数值 c != 0
        // 那么就返回 false
        if(c == 0) return true;
        else if(i == nums.size()) return false;

        bool no_select = false;
        bool select = false;

        // 不选择 i+1 号数值
        no_select = backtrack(nums, i+1, c);

        // 选择 i+1 号数值
        if(c-nums[i+1] >= 0)
            select = backtrack(nums, i+1, c-nums[i]);

        return no_select || select;
    }

};


int main()
{
    vector<int> nums = {1, 5, 11, 5};
    bool res = Solution().canPartition(nums);
    cout << "res : " << res;
    return 0;
}