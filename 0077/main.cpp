class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        findCombination(cur, 1, k, n, res);
        return res;
    }

    void findCombination(vector<int>& cur, int index, int k, int n, vector<vector<int>>& res) {
        if( cur.size() >= k ) {
            res.push_back(cur);
            return;
        }

        // index 是当前这一轮选择的起点
        // index - 1 是上一轮选择的位置
        for( int i = index ; i <= n ; i++ ) {
            cur.push_back(i);
            findCombination(cur, i+1, k, n, res);
            cur.pop_back();
        }
    }
};
