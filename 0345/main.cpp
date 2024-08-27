class Solution {
public:
    bool isVowels(char c) {
        c = tolower(c);
        if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
            return true;

        return false;
    }

    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;

        while( i <= j ) {
            if( !this->isVowels(s[i]) ) i++;
            else if( !this->isVowels(s[j]) ) j--;
            else {
                swap(s[i++], s[j--]);
            }
        }

        return s;
    }
};
