class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        // 使用排序 + isUsedValue + 每次之后选择上一轮选择元素的后方元素 来避免出现相同的组合
        sort(candidates.begin(), candidates.end());
        findCombinationSum2(cur, 0, 0, candidates, target, res);
        return res;
    }


    void findCombinationSum2(vector<int>& cur, int sum, int index, vector<int>& candidates, int target, vector<vector<int>>& res) {
        if( sum > target ) {
            return;
        }

        if( sum == target ) {
            res.push_back(cur);
            return;
        }

        // 保证组合的前方数值没有变化的情况下, 当前数值在当前位置只能出现一次
        vector<bool> isUsedValue(51, false);
        for( int i = index ; i < candidates.size() ; i++ ) {
            if( isUsedValue[candidates[i]] ) continue;

            isUsedValue[candidates[i]] = true;
            cur.push_back(candidates[i]);
            findCombinationSum2(cur, sum + candidates[i], i+1, candidates, target, res);
            cur.pop_back();
        }
    }
};
