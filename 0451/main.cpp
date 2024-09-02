#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        int record[256];
        map<int, vector<char>> freq;

        for( int i = 0 ; i < 256 ; i ++ ) {
            record[i] = 0;
        }

        for( int i = 0 ; i < s.size() ; i++ ) {
            record[s[i]] += 1;
        }

        ostringstream oss;

        for( int i = 0 ; i < 256 ; i++ ) {
            int counter = record[i];
            char ch = (char)i;

            if( counter != 0 ) {
                freq[counter].push_back(ch);
            }
        }

        for( auto iter = freq.rbegin() ; iter != freq.rend() ; iter++ ) {
            for( int i = 0 ; i < iter->second.size() ; i++ ) {
                for( int j = 0 ; j < iter->first ; j++ ) {
                    oss << iter->second[i];
                }
            }
        }

        return oss.str();
    }
};


int main() {

    string ss = "tree";

    Solution solution;
    string res = solution.frequencySort(ss);
    cout << res;
    return 0;
}
