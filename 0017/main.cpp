class Solution {
private:

    vector<string> record = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if( digits == "" ) {
            return res;
        }

        findCombinations(digits, 0, "", res);

        return res;
    }

    void findCombinations(string& digits, int i, string s, vector<string>& res) {
        if( s.size() == digits.size() ) {
            res.push_back(s);
            return;
        }

        for( int j = 0 ; j < this->record[digits[i]-'0'].size() ; j++ ) {
            char ch = this->record[digits[i]-'0'][j];
            findCombinations(digits, i+1, s + ch, res);
        }
    }
};
