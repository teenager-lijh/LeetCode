class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // [0...r) 是非零元素的区间
        // [0...0) 表示空区间

        int r = 0;
        for( int i = 0 ; i < nums.size() ; i++ ) {
            if( nums[i] != 0 ) {
                nums[r++] = nums[i];
            }
        }

        for( int i = r ; i < nums.size() ; i++ ) {
            nums[i] = 0;
        }
    }
};
