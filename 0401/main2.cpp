class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        vector<bool> cur(turnedOn, false);

        if( turnedOn == 0 ) {
            res.push_back("0:00");
            return res;
        }

        findBinaryTime(turnedOn, 0, 0, 0, res);
        return res;
    }

    bool isValid(int cur) {
        int hour = cur >> 6;
        int minute = cur & 0x0000003F;

        if( hour >= 12 || minute > 59 ) {
            return false;
        }

        return true;
    }
    

    void findBinaryTime(int turnedOn, int cur, int index, int start, vector<string>& res) {

        if( index >= turnedOn ) {
            // 保存结果
            int hour = cur >> 6;
            int minute = cur & 0x0000003F;

            if( hour >= 12 || minute > 59 ) return;

            string h = to_string(hour);
            string m = to_string(minute);

            if( m.size() <= 1 ) m = "0" + m;
            res.push_back(h + ":" + m);
            return;
        }

        for( int s = start ; s <= 9 ; s++ ) {
            int shift = 9 - s;
            int new_cur = cur | (0x1 << shift);
            if( !isValid(new_cur) ) continue;

            findBinaryTime(turnedOn, new_cur, index+1, s+1, res);
        }
    }
};
