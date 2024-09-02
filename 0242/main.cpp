#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[256];

        for( int i = 0 ; i < 256 ; i++ ) {
            freq[i] = 0;
        }

        for( int i = 0 ; i < s.size() ; i++ ) {
            freq[s[i]] += 1;
        }

        for( int i = 0 ; i < t.size() ; i++ ) {
            freq[t[i]] -= 1;
        }

        for( int i = 0 ; i < 256 ; i++ ) {
            if( freq[i] != 0 ) return false;
        }

        return true;
    }
};


int main() {
    map<int, int> freq;

    for( int i = 0 ; i < 10 ; ++i ) {
        freq[i] = 11 * i;
    }

    for( map<int, int>::iterator iter = freq.begin(); iter != freq.end() ; iter++ ) {
        cout << iter->first;
    }
}
