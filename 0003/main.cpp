class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256];

        for( int i = 0 ; i < 256 ; i++ ) {
            freq[i] = 0;
        }

        // 使用带记录的滑动窗口寻找最长的无重复子串
        // s[l...r]

        int max_len = 0;
        for( int l = 0, r = 0 ; r < s.size() ; r++ ) {
            char ch = s[r];
            freq[ch] ++;

            if( freq[ch] == 1 ) {
                max_len = max(max_len, r-l+1);
            } else {

                while( l < r && freq[s[l]] == 1 ) {
                    freq[s[l]] --;
                    l++;
                }

                freq[s[l]] --;
                l++;

            }
        }

        return max_len;
    }
};
