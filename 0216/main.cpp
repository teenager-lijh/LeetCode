// 指定数量的组合
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        findCombinationSum3(cur, 0, 1, n, k, res);
        return res;

    }

    void findCombinationSum3(vector<int>& cur, int sum, int start, int n, int k, vector<vector<int>>& res) {
        if(cur.size() >= k) {
            if(sum == n) res.push_back(cur);
            return;
        }

        for( int s = start ; s <= 9 ; s++ ) {
            int new_sum = sum + s;
            if( new_sum > n ) continue;
            cur.push_back(s);
            findCombinationSum3(cur, new_sum, s+1, n, k, res);
            cur.pop_back();
        }
    }
};
