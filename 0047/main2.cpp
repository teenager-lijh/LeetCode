class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        findPermuteUnique(nums, 0, res);

        return res;
    }

    void findPermuteUnique(vector<int>& nums, int index, vector<vector<int>>& res) {
        if( index >= nums.size() ) {
            res.push_back(nums);
            return;
        }

        // -10 <= nums[i] <= 10
        vector<bool> isUsedValue(21, false);
        
        for( int i = index ; i < nums.size() ; i++ ) {
            if( !isUsedValue[nums[i]+10] ) {
                isUsedValue[nums[i]+10] = true;
                swap(nums[index], nums[i]);
                findPermuteUnique(nums, index+1, res);
                swap(nums[index], nums[i]);
            }
        }
    }
};
