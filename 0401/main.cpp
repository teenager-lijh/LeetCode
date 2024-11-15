// 可以使用位运算来优化
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        // 从 0 到 9 中选取出来 turnedOn 个数值
        // 前 0-3  这几个位置的数值表示小时的 LED
        // 前 4-9 这几个位置的数值表示分钟的 LED
        vector<string> res;
        vector<bool> cur(turnedOn, false);

        if( turnedOn == 0 ) {
            res.push_back("0:00");
            return res;
        }

        findBinaryTime(turnedOn, cur, 0, 0, res);
        return res;
    }
    
    // index = [0...turnedOn-1]
    // start = [0...9]
    // cur.size() == turnedOn
    void findBinaryTime(int turnedOn, vector<bool>& cur, int index, int start, vector<string>& res) {

        if( index >= turnedOn ) {
            // 保存结果
            int hour = (int)cur[0] * 8 + (int)cur[1] * 4 + (int)cur[2] * 2 + (int)cur[3];
            int minute = (int)cur[4] * 32 + (int)cur[5] * 16 + (int)cur[6] * 8 + (int)cur[7] * 4 + (int)cur[8] * 2 + (int)cur[9];

            if( hour >= 12 || minute > 59 ) return;

            string h = to_string(hour);
            string m = to_string(minute);

            if( m.size() <= 1 ) m = "0" + m;
            res.push_back(h + ":" + m);
            return;
        }

        for( int s = start ; s <= 9 ; s++ ) {
            cur[s] = true;
            findBinaryTime(turnedOn, cur, index+1, s+1, res);
            cur[s] = false;
        }
    }
}
