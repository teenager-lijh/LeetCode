// map 的使用
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;

        for( int i = 0 ; i < nums1.size(); i++ ) {
            record[nums1[i]] ++;
        }

        vector<int> res;

        for( int i = 0 ; i < nums2.size() ; i++ ) {
            if( record.find( nums2[i] ) != record.end() && record[nums2[i]] > 0 ) {
                record[nums2[i]] --;
                res.push_back( nums2[i] );
            }
        }

        return res;
    }
};
