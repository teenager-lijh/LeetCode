class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> record;

        for( int i = 0 ; i < nums.size() ; i++ ) {
            record[nums[i]] += 1;
        }

        // 排序
        sort(nums.begin(), nums.end());

        // 去重
        vector<int>::iterator iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());

        // result
        vector<vector<int>> res;

        if( record[0] >= 3 ) {
            res.push_back({0, 0, 0});
        }

        // 使用查找表 优化一层循环
        for( int i = 0 ; i < nums.size() ; i++ ) {
            for( int j = i+1; j < nums.size() ; j++ ) {
                // 最内层使用 hash table

                // 1 nums[i] 用两次 但 nums[j] 用一次的情况
                if( 2 * nums[i] + nums[j] == 0 && record[nums[i]] >= 2 ) {
                    res.push_back(vector<int>({nums[i], nums[i], nums[j]}));
                }

                // 2 nums[i] 用一次 但 nums[j] 用两次的情况
                if( nums[i] + 2 * nums[j] == 0 && record[nums[j]] >= 2 ) {
                    res.push_back(vector<int>({nums[i], nums[j], nums[j]}));
                }

                // 3 nums[i] 用一次 nums[j] 用一次 && 从剩余的元素中寻找一个
                // 最内层循环中寻找的那个值一定是排在前两个值后面的
                int target = - ( nums[i] + nums[j] );
                if( record.find(target) != record.end() && target > nums[j] ) {
                    res.push_back(vector<int>({nums[i], nums[j], target}));
                }
            }
        }

        return res;

    }
};
