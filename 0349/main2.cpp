class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record( nums1.begin(), nums1.end() );
        
        set<int> resultSet;
        for( int i = 0 ; i < nums2.size() ; i++ ) {
            if( record.find(nums2[i]) != record.end() ) resultSet.insert(nums2[i]);
        }

        vector<int> res( resultSet.begin(), resultSet.end() );

        return res;
    }

};
