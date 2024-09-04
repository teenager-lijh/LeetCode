class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();

        unordered_map<int, int> record1;
        unordered_map<int, int> record2;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                record1[nums1[i] + nums2[j]] += 1;
                record2[nums3[i] + nums4[j]] += 1;
            }
        }

        int res = 0;
        for( unordered_map<int, int>::iterator iter = record1.begin() ; iter != record1.end() ; iter++ ) {
            int c = - iter->first;
            if( record2.find(c) != record2.end() ) {
                res += iter->second * record2[c];
            }
        }

        return res;
    }
};
