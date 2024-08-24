class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // [0...k) 区间维护不等于 val 的元素
        int k = 0;

        for( int i = 0 ; i < nums.size() ; i++ ) {
            if( nums[i] != val ) {
                if( k != i ) {
                    swap(nums[k++], nums[i]);
                } else {
                    k++;
                }
                
            }
        }

        return k;
    }
};
