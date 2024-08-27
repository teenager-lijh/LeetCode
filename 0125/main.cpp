#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAlpha(char c) {
        if(c >= 'a' && c <= 'z')
            return true;

        if(c >= 'A' && c <= 'Z')
            return true;

        if(c >= '0' && c <= '9')
            return true;

        return false;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while( i <= j ) {
            if( !this->isAlpha(s[i]) ) {
                i++;
            } else if ( !this->isAlpha(s[j]) ) {
                j--;
            } else if( tolower(s[i]) == tolower(s[j]) ) {
                i++, j--;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    bool res = solution.isPalindrome(s);
    cout << res;
    return 0;
}
