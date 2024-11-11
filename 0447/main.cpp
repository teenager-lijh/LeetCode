class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        // reocrd[i][j] 到节点 i 并且距离为 j 的点有 record[i][j] 个
        vector<unordered_map<int, int>> record(points.size());

        for( int i = 0 ; i < points.size() ; i++ ) {
            for( int j = 0 ; j < points.size(); j++ ) {
                int dis = distance(points[i], points[j]);
                record[i][dis] += 1;
            }
        }

        int res = 0;
        for( int i = 0 ; i < record.size() ; i++ ) {
            for( unordered_map<int, int>::iterator iter = record[i].begin() ; iter != record[i].end() ; iter++ ) {
                int k = iter->second;
                res += k * (k - 1);
            }
        }

        return res;

    }

    int distance(vector<int>& x, vector<int>& y) {

        int a = x[0] - y[0];
        int b = x[1] - y[1];
        // 距离没必要开放 ==> 保证唯一性
        int c = a * a + b * b;

        return c;
    }
};
