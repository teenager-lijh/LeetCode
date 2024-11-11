class Solution {
public:

    vector<string> splitString(string& path) {
        vector<string> res;

        int s = 0;
        for( int i = 0 ; i < path.size() ; i++ ) {
            if( path[i] == '/' ) {
                if( i-s != 0 ) {
                    res.push_back(path.substr(s, i-s));
                }
                s = i+1;
            } else if( i+1 >= path.size() ) {
                res.push_back(path.substr(s, i-s+1));
            }
        }

        return res;
    }

    string simplifyPath(string path) {
        vector<string> paths = splitString(path);

        stack<string> record;

        for( int i = 0 ; i < paths.size() ; i++ ) {
            if( paths[i] == string("..") ) {
                if( !record.empty() )
                    record.pop();
            } else if( paths[i] != string(".") ) {
                record.push(paths[i]);
            }
        }

        stack<string> res;
        while(  !record.empty() ) {
            res.push(record.top());
            record.pop();
        }

        string result = "";
        while( !res.empty() ) {
            result += "/" + res.top();
            res.pop();
        }

        if( result.size() == 0 ) {
            return "/";
        }
        
        return result;
    }
};
