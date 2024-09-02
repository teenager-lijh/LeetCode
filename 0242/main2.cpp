class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int, int> freq;

        for( int i = 0 ; i < s.size() ; i++ ) {
            freq[s[i]] += 1;
        }

        for( int i = 0 ; i < t.size() ; i++ ) {
            freq[t[i]] -= 1;
        }

        for(map<int, int>::iterator iter = freq.begin() ; iter != freq.end() ; iter++ ) {
            if( iter->second != 0 ) return false; 
        }

        return true;
    }
};
