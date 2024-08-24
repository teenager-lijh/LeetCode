#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 使用三路快拍的思想 完成一次 partition

        // [0...l) 是 0 元素的区间
        // [l...i) 是 1 元素的区间
        // (k...n-1] 是 2 元素的区间

        int l = 0, k = nums.size() - 1;
        for( int i = 0 ; i <= k ; ) {
            if( nums[i] == 0 ) {
                // 如果 1 区间为空 就是自己和自己交换 此时 i == l 成立
                swap(nums[i++], nums[l++]);
            } else if( nums[i] == 1 ) {
                i++;
            } else if( nums[i] == 2 ) {
                swap(nums[i], nums[k--]);
            }
        }
    }
};

int main() {

    vector<int> nums = {0, 0, 1, 1, 2, 2};

    Solution solution;
    solution.sortColors(nums);

    for( int i = 0 ; i < nums.size() ; i++ ) {
        cout << nums[i];
    }

    return 0;
}
