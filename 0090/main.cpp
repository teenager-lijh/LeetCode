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

        // 使用 hash table 完成记录
        unordered_set<int> record;
        for( int s = start ; s < nums.size() ; s++ ) {
            if( record.find(nums[s]) != record.end() ) continue;
            record.insert(nums[s]);

            cur.push_back(nums[s]);
            findSubsetsWithDup(nums, cur, s+1, res);
            cur.pop_back();
        }
    }
};
