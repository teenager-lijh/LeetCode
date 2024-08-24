class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 把所有的非零元素从 nums 里面拿出来放在 nonZeroNums 中
        // 然后再把 nonZeroNums 中的元素放回 nums
        // nums 的其他元素赋值为 0
        vector<int> nonZeroNums;

        for( int i = 0 ; i < nums.size() ; i++ ) {
            if( nums[i] != 0 )
                nonZeroNums.push_back( nums[i] );
        }

        for( int i = 0 ; i < nonZeroNums.size() ; i++ ) {
            nums[i] = nonZeroNums[i];
        }

        for( int i = nonZeroNums.size() ; i < nums.size() ; i++ ) {
            nums[i] = 0;
        }
    }
};
