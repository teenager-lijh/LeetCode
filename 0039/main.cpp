// 如果每一步都可以选择任意数值的话
// 这样就会造成重复
// 如果只允许无限使用的数值只能连续使用
// 这样就不会造成重复了
// 比如：如果想用 3 次 2 就必须是 2, 2, 2
// 一旦当前不选择 2 了, 以后就再也没有机会选择 2 了
// 这样不会造成出现 2, 2, 3 和 3, 2, 2 这种类似的重复出现
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        findCombinationSum(cur, 0, 0, candidates, target, res);
        return res;
    }

    void findCombinationSum(vector<int>& cur, int index, int sum, vector<int>& candidates, int target, vector<vector<int>>& res) {
        if( sum > target || index >= candidates.size() ) {
            return;
        }

        if( sum == target ) {
            res.push_back(cur);
            return;
        }

        // 不选择当前的数值 并且下一轮没有机会选
        findCombinationSum(cur, index+1, sum, candidates, target, res);

        // 选择当前的数值 并且下一轮还有机会选
        cur.push_back(candidates[index]);
        findCombinationSum(cur, index, sum + candidates[index], candidates, target, res);
        cur.pop_back();

    }
};
