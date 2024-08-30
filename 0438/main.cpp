class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int freq[256];
        int counter = 0;

        vector<int> res;

        for( int i = 0 ; i < p.size(); i++ ) {
            freq[p[i]] += 1;
            counter += 1;
        }

        int l = 0, r = -1;
        
        while( l < s.size() ) {
            if( r+1 < s.size() && freq[s[r+1]] >= 1 ) {
                r += 1;
                freq[s[r]] --;
                counter --;
            } else {
                freq[s[l++]] ++;
                counter ++;
            }

            // 每次尝试移动一次后，看看是不是满足条件了
            if( counter == 0 ) {
                res.push_back(l);
            }

        }

        return res;

    }
};
