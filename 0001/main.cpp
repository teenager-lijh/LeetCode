class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 使用查找表
        unordered_map<int, int> record;

        for( int i =  0 ; i < nums.size() ; i++ ) {
            int v = nums[i];

            if( record.find( target - v ) != record.end() ) {
                vector<int> res;
                res.push_back(record[target-v]);
                res.push_back(i);
                return res;
            }

            record[v] = i;
        }

        return vector<int>();
    }
};
