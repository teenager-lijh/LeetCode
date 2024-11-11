class Solution {
public:
    bool isValid(string s) {
        stack<char> record;

        for( int i = 0 ; i < s.size(); i++ ) {
            if( s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
                record.push(s[i]);
            } else {
                if( record.size() == 0 ) {
                    return false;
                }
                
                char top = record.top();
                record.pop();
                bool c1 = (top == '(' && s[i] == ')');
                bool c2 = (top == '{' && s[i] == '}');
                bool c3 = (top == '[' && s[i] == ']');

                if( c1 || c2 || c3 ) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        if( record.size() == 0 ) {
            return true;
        } else {
            return false;
        }
    }
};
