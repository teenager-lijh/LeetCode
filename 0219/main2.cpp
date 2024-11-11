class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 滑动窗口 + 查找表

        unordered_set<int> record;

        for( int i = 0 ; i < nums.size() ; i++ ) {
            if( record.find(nums[i]) != record.end() ) {
                return true;
            }

            record.insert(nums[i]);

            // record 中最多只能有 k 个元素
            if( record.size() >= k+1 ) {
                record.erase(nums[i-k]);
            }
        }

        return false;
    }
};
