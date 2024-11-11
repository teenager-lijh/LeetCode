class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        if( nums.size() <= 1 || k == 0 ) {
            return false;
        }

        // 滑动窗口 + 查找表
        unordered_set<int> record;

        for( int i = 0 ; i <= k && i < nums.size() ; i++ ) {
            if( record.find(nums[i]) != record.end() ) {
                return true;
            }
            record.insert(nums[i]);
        }

        // 维护滑动窗口为 k + 1 (1 为当前考虑的元素)
        if( k < nums.size() ) {
            record.erase(nums[k]);
        }
        

        for( int i = k+1 ; i < nums.size() ; i++ ) {
            // 移除左端的元素 && 添加上一轮的元素
            record.erase(nums[i-1-k]);
            record.insert(nums[i-1]);
            
            if( record.find(nums[i]) != record.end() ) {
                return true;
            }
        }

        return false;
    }
};
