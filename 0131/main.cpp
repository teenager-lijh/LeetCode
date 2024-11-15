class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> record;
        vector<string> cur;
        findPartition(cur, s, 0, record);
        return record;
    }

    bool inline isValid(string& s) {
        int n = s.size()-1;
        int sz = s.size() / 2;
        for( int i = 0 ; i < sz ; i++ ) {
            if(s[i] != s[n-i]) return false;
        }

        return true;
    }

    void findPartition(vector<string>& cur, string& s, int index, vector<vector<string>>& record) {
        if( index >= s.size() ) {
            record.push_back(cur);
            return;
        }

        for( int i = index ; i < s.size() ; i++ ) {
            int sz = i - index + 1;
            string part = s.substr(index, sz);
            if( !isValid(part) ) continue;

            cur.push_back(part);
            findPartition(cur, s, i+1, record);
            cur.pop_back();
        }
    }
};
