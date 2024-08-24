class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // 使用一个长度为 m+n 的数组 nums 来合并 m 和 n
        vector<int> nums(m+n, 0);

        int i = 0;
        int j = 0;
        int k = 0;

        while( i < m && j < n ) {
            if( nums1[i] < nums2[j] ) {
                nums[k++] = nums1[i++];
            } else {
                nums[k++] = nums2[j++];
            }
        }
        
        if( i >= m ) {
            while( j < n ) {
                nums[k++] = nums2[j++];
            }
        } else {
            while( i < m ) {
                nums[k++] = nums1[i++];
            }
        }

        for( i = 0 ; i < m+n ; i++ ) {
            nums1[i] = nums[i];
        }
    }
};
