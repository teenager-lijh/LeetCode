class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        // 滑动窗口 + 顺序查找表(ceil 操作)
        // ceil 和 floor
        // 1. ceil(v)  是指 大于等于 v 的最小的元素
        // 2. floor(v) 是指 小于等于 v 的最大的那个元素
        set<long long> record;

        for( int i = 0 ; i < nums.size() ; i++ ) {
            
            if( record.lower_bound((long long)nums[i] - (long long)valueDiff) != record.end() && 
                *record.lower_bound((long long)nums[i] - (long long)valueDiff) <= (long long)nums[i]+(long long)valueDiff ) {
                return true;
            }


            record.insert(nums[i]);
            if( record.size() == indexDiff+1 ) {
                record.erase(nums[i-indexDiff]);
            }

        }
        
        return false;
    }
};
