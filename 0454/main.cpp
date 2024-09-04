// 查找表 - 键值选择
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> record;

        for( int i = 0 ; i < nums3.size() ; i++ ) {
            for( int j = 0 ; j < nums4.size() ; j++ ) {
                record[nums3[i] + nums4[j]] += 1;
            }
        }

        int res = 0;
        for( int i = 0 ; i < nums1.size() ; i++ ) {
            for( int j = 0 ; j < nums2.size() ; j++ ) {
                int c = - (nums1[i] + nums2[j]);
                if( record.find(c) != record.end() ) {
                    res += record[c];
                }
            }
        }

        return res;
    }
};
