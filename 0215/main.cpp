#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    void partition(vector<int>& nums, int l, int r, int& rl, int& rr) {
        // 三路快排的思想
        // 对 nums[l...r] 区间内的元素进行查找
        // 返回递增排序中 nums[l] 所在数组中的位置

        // nums[l...j) < v
        // nums[j...i-1) = v
        // nums(k...r] > v

        // nums[i-1] 这个位置才是空着的
        // nums[k] 这个位置也是空着的
        // 循环结束的时候 k == i-1

        int k = r, j = l;
        int v = nums[l];
        for(int i = l+1 ; i <= k ; ) {
            if(nums[i] == v) {
                nums[i-1] = nums[i], i++;
            } else if(nums[i] > v) {
                // nums[i] > v
                swap(nums[i], nums[k--]);
            } else {
                // nums[i] < v
                nums[i-1] = nums[i];
                swap(nums[i-1], nums[j++]);
                i++;
            }
        }

        nums[k] = v;
        rl = j;
        rr = k;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;

        // 对 nums[l...r] 进行搜索
        while( l <= r ) {
            int rl, rr;
            partition(nums, l, r, rl, rr);
            int lk = nums.size() - rl;
            int rk = nums.size() - rr;

            if( lk >= k && rk <= k ) {
                // 找到了
                int idx = nums.size() - k;
                return nums[idx];
            }

            if( k < rk ) {
                // 继续找更大的
                l = nums.size() - rk + 1;
            } else {
                // 继续找更小的
                r = nums.size() - lk - 1;
            }
        }

        return 0;
    }
};

int main() {

    vector<int> nums = {3, 2, 1, 5, 6, 4};

    Solution solution;

    int res = solution.findKthLargest(nums, 2);

    cout << "res : " << res;

    return 0;
}
