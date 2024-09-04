#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long target2 = target;
        unordered_map<int, int> record;

        for( int i = 0 ; i < nums.size() ; i++ ) {
            record[nums[i]] += 1;
        }

        // 排序
        sort(nums.begin(), nums.end());

        // 去重
        vector<int>::iterator iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());

        vector<vector<int>> res;

        // 都不重复的情况下
        for(int i = 0 ; i < nums.size() ; i++) {
            // 4 个的情况
            if( record[nums[i]] >= 4 && target2 - nums[i] - nums[i] - nums[i]- nums[i] == 0 ) {
                res.push_back(vector<int>( {nums[i], nums[i], nums[i], nums[i]} ));
            }

            for(int j = i+1 ; j < nums.size() ; j++) {
                // 3 个的情况
                if( record[nums[i]] >= 3 && target2 - nums[i] - nums[i] - nums[i] - nums[j] == 0 ) {
                    res.push_back(vector<int>( {nums[i], nums[i], nums[i], nums[j]} ));
                }

                // 2 个的情况
                if( record[nums[i]] >= 2 && record[nums[j]] >= 2 && target2 - nums[i] - nums[i] - nums[j] - nums[j] == 0 ) {
                    res.push_back(vector<int>( {nums[i], nums[i], nums[j], nums[j]} ));
                }

                // 3 个的情况
                if( record[nums[j]] >= 3 && target2 - nums[i] - nums[j] - nums[j] - nums[j] == 0 ) {
                    res.push_back(vector<int>( {nums[i], nums[j], nums[j], nums[j]} ));
                }

                for(int k = j+1 ; k < nums.size() ; k++) {
                    // 前两个重复 - 后两个不重复
                    if( record[nums[i]] >= 2 && target2 - nums[i] - nums[i] - nums[j] - nums[k] == 0 ) {
                        res.push_back(vector<int>( {nums[i], nums[i], nums[j], nums[k]} ));
                    }

                    // 前两个不重复 - 后两个重复
                    if( record[nums[k]] >= 2 && target2 - nums[i] - nums[j] - nums[k] - nums[k] == 0 ) {
                        res.push_back(vector<int>( {nums[i], nums[j], nums[k], nums[k]} ));
                    }

                    // 两边不重复 - 中间重复
                    if( record[nums[j]] >= 2 && target2 - nums[i] - nums[j] - nums[j] - nums[k] == 0 ) {
                        res.push_back(vector<int>( {nums[i], nums[j], nums[j], nums[k]} ));
                    }

                    // 都不重复
                    int c = target2 - nums[i] - nums[j] - nums[k];
                    if(record.find(c) != record.end() && c > nums[k]) {
                        res.push_back( {nums[i], nums[j], nums[k], c } );
                    }
                }
            }
        }

        return res;
    }
};

int main() {

    vector<int> nums = {0,1,5,0,1,5,5,-4};
    int target = 11;

    Solution solution;
    vector<vector<int>> res = solution.fourSum(nums, target);

    for( int i = 0 ; i < res.size() ; i++ ) {
        for( int j = 0 ; j < res[i].size() ; j++ ) {
            cout << res[i][j] << ", ";
        }

        cout << endl;
    }

    return 0;
}
