#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        int freq[256];
        bool which[256];

        for( int i = 0 ; i < 256 ; i++ ) {
            freq[i] = 0;
            which[i] = false;
        }

        int counter = 0;
        for( int i = 0 ; i < t.size() ; i++ ) {
            which[t[i]] = true;
            freq[t[i]] += 1;
            counter += 1;
        }

        int min_l = -1, min_r = -1;
        int minimum_len = 1000000;

        int l = 0, r = -1;
        while( l < s.size() ) {
            // 在没有覆盖全部字符的时候向右滑动
            if( r+1 < s.size() && counter >= 1 ) {
                if( which[s[r+1]] ) {
                    // 已经满足的情况下 counter 不需要 --
                    if( freq[s[r+1]] >= 1 ) counter --;
                    freq[s[r+1]] --;
                }
                r++;
            } else {
                // 丢掉当前 l 位置的元素 ==> 逐渐缩小窗口
                if( which[s[l]] ) {
                    // 丢掉一个字符后依然满足情况 counter 不需要 ++
                    if( freq[s[l]] >= 0 ) counter ++;
                    freq[s[l]] ++;
                }
                l++;
            }

            // 每次移动之后 看一下 如果满足的话 记录当前的最小长度
            if( counter <= 0 ) {
                if( r-l+1 < minimum_len && r-l+1 > 0 ) {
                    minimum_len = r-l+1;
                    min_l = l;
                    min_r = r;
                }
            }
        }

        if( minimum_len == 1000000 ) {
            return "";
        }

        return s.substr(min_l, min_r-min_l+1);
    }
};


int main() {

    string s = "bba";
    string t = "ab";

//    string s = "ab";
//    string t = "a";

    Solution solution;
    string res = solution.minWindow(s, t);
    cout << "res : " << res << endl;
    return 0;
}
