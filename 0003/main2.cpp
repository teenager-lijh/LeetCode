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
        int l = 0, r = -1;

        while( l < s.size() ) {
            int size = s.size();

            // 先去在允许范围内尝试拓展右边界
            if( r+1 < size && freq[s[r+1]] == 0 ) {
                freq[s[++r]] ++;
            } else {
                // 右边界无法拓展 说明只能尝试缩小左边界了
                freq[s[l++]] --;
            }

            max_len = max(max_len, r-l+1);
        }

        return max_len;
    }
};
