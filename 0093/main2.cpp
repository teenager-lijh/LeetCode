// 使用减枝优化
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> record;
        vector<string> cur;
        cur.push_back(s);
        findIpAddress(cur, record);
        return record;
    }

    void findIpAddress(vector<string> cur, vector<string>& record) {
        if( cur.size() == 4 ) {
            string last = cur[cur.size()-1];
            if( last.size() >= 4 || stoi(last) > 255 ) return;
            if(last.size() >= 2 && last[0] == '0') return;

            record.push_back(cur[0] + "." + cur[1] + "." + cur[2] + "." + cur[3]);
            return;
        }

        int step = cur.size();
        string last = cur[cur.size()-1];

        for( int i = 0 ; i < 3 && i < last.size() - 1 ; i++ ) {
            string part = last.substr(0, i+1);
            string new_last = last.substr(i+1, last.size()-i-1);

            if(stoi(part) > 255) break;
            if(part.size() >= 2 && part[0] == '0') break;

            // 减枝 如果插入第 step 个点之后
            // 剩余需要处理的数字的个数必须要小于等于 (4-step)*3
            if(new_last.size() > (4-step) * 3) continue;

            cur.pop_back();
            cur.push_back(part);
            cur.push_back(new_last);

            findIpAddress(cur, record);

            cur.pop_back();
            cur.pop_back();
            cur.push_back(last);
        }
    }
};
