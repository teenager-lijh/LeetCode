#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> record;
        unordered_map<string, char> words;

        int i = 0;
        int l = -2, r = -2;
        for( i = 0 ; i < pattern.size() ; i++ ) {
            char p = pattern[i];

            r += 2;  // 跳到下一个单词的开始位置
            l = r;  // 跳到下一个单词的开始位置
            // 寻找下一个单词的结束位置
            while( s[r+1] != ' ' && r+1 < s.size() ) {
                r++;
            }

            if( r >= s.size() ) {
                return false;
            }

            // 1 检查字符到单词的映射
            string ss = s.substr(l, r-l+1);
            if( record[p] != "" && record[p] != ss ) {
                return false;
            } else {
                record[p] = ss;
            }

            // 2 检查单词到字符的映射
            if( words.find(ss) != words.end() && words[ss] != p ) {
                return false;
            } else {
                words[ss] = p;
            }
        }

        if( i >= pattern.size() && r+1 >= s.size() ) {
            return true;
        }

        return false;
    }
};


int main() {
    Solution solution;

    string pattern = "abba";
    string s = "dog dog dog dog";

    bool res = solution.wordPattern(pattern, s);
    cout << res;

    return 0;
}
