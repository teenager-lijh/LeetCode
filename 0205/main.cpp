class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map_st;
        unordered_map<char, char> map_ts;

        if( s.size() != t.size() ) return false;

        for( int i = 0 ; i < s.size() ; i++ ) {
            char ss = s[i];
            char tt = t[i];

            // 1 看 ss ==> tt 的映射
            if( map_st.find( ss ) != map_st.end() && map_st[ss] != tt ) {
                return false;
            } else {
                map_st[ss] = tt;
            }

            // 2 看 tt ==> ss 的映射
            if( map_ts.find( tt ) != map_ts.end() && map_ts[tt] != ss ) {
                return false;
            } else {
                map_ts[tt] = ss;
            }
        }

        return true;

    }
};
