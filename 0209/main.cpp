#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;

        // nums[l...r) 是否满足 target 要求
        // 1. 满足记录条件 ==> 向右滑动 l
        // 2. 不满足      ==> 向右滑动 r 直到满足 或 结束

        int container = 0;
        int minimum_size = 1000000;

        // nums
        while(r <= nums.size()) {
            int size = r-l;
            if( container >= target && size < minimum_size ) {
                minimum_size = size;
            }

            if( container >= target ) {
                container -= nums[l++];
            } else if( r < nums.size() ) {
                container += nums[r++];
            } else {
                break;
            }
        }

        if(minimum_size == 1000000) {
            return 0;
        }

        return minimum_size;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    int res = solution.minSubArrayLen(7, nums);
    cout << res << endl;
    return 0;
}
