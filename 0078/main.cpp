// 寻找所有的子集
// 就是寻找所有的组合
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;

        findSubsets(nums, cur, 0, res);
        return res;
    }

    void findSubsets(vector<int>& nums, vector<int>& cur, int start, vector<vector<int>>& res) {
        res.push_back(cur);

        if(start >= nums.size()) return;

        for( int s = start ; s < nums.size() ; s++ ) {
            cur.push_back(nums[s]);
            findSubsets(nums, cur, s+1, res);
            cur.pop_back();
        }
    }
};
