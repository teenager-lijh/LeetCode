//
// Created by 李嘉豪 on 2022/10/16.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        const int n = 1000;

        bool left[n+1];
        bool right[n+1];

        for(int i = 0 ; i <= n ; ++i) {
            left[i] = false;
            right[i] = false;
        }

        for(int i = 0 ; i < nums.size(); ++i) {
            if(nums[i] < 0)
                left[-nums[i]] = true;
            if(nums[i] > 0)
                right[nums[i]] = true;
        }

        int res = -1;

        for(int i = 0 ; i <= n ; ++i) {
            if(left[i] && right[i])
                res = i;
        }

        return res;
    }
};

int main() {




    return 0;
}
