class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        // 排序 + record + start+1 ==> 避免重复
        sort(nums.begin(), nums.end());
        findSubsetsWithDup(nums, cur, 0, res);
        return res;
    }

    void findSubsetsWithDup(vector<int>& nums, vector<int>& cur, int start, vector<vector<int>>& res) {
        res.push_back(cur);

        if(start >= nums.size()) return;

        // 使用 数组 完成记录
        vector<bool> isUsedValue(21, false);
        for( int s = start ; s < nums.size() ; s++ ) {
            if( isUsedValue[nums[s]+10] ) continue;
            isUsedValue[nums[s]+10] = true;

            cur.push_back(nums[s]);
            findSubsetsWithDup(nums, cur, s+1, res);
            cur.pop_back();
        }
    }
};
