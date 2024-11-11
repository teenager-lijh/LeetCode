class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> record;

        for( int i = 0 ; i < tokens.size() ; i++ ) {
            if( tokens[i] != string("+") && tokens[i] != string("-") && tokens[i] != string("*") && tokens[i] != string("/") ) {
                record.push(stoi(tokens[i]));
            } else {
                // 运算
                string op = tokens[i];
                int v2 = record.top(); record.pop();
                int v1 = record.top(); record.pop();

                if( op == string("+") ) {
                    record.push(v1 + v2);
                } else if( op == string("-") ) {
                    record.push(v1 - v2);
                } else if( op == string("*") ) {
                    record.push(v1 * v2);
                } else {
                    record.push(v1 / v2);
                }
            }
        }

        int res = record.top(); record.pop();

        return res;
    }
};
