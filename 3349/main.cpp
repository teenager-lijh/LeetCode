class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // 滑动窗口
        int wz = 2 * k;
        
        int l = 0;
        int r = 2 * k - 1;
        int mid = l + k - 1; // 左侧的结尾
        
        while(r < nums.size()) {
            bool ok = true;
            for( int i = l ; i < mid ; i++ ) {
                if( nums[i] >= nums[i+1] ) {
                    ok = false;
                    break;
                }
            }
            
            for( int i = mid+1 ; i < r && ok ; i++ ) {
                if( nums[i] >= nums[i+1] ) {
                    ok = false;
                    break;
                }
            }
            
            if(ok) return true;
            l += 1;
            mid += 1;
            r += 1;
        }
        
        return false;
    }
};
