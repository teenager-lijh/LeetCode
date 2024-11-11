class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // word & visted
        unordered_map<string, bool> record;

        for( int i = 0 ; i < wordList.size() ; i++ ) {
            record[wordList[i]] = false;
        }

        // word & step
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));

        while(!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            for( int i = 0 ; i < word.size() ; i++ ) {
                for( char c = 'a' ; c <= 'z' ; c++ ) {
                    string next = word;
                    next[i] = c;
                    if(record.find(next) != record.end()) {
                        if( record[next] == false ) {
                            
                            // check
                            if( next == endWord ) {
                                return step + 1;
                            }

                            q.push(make_pair(next, step+1));
                            record[next] = true;
                        }
                    }
                }
            }

        }
        
        return 0;
    }
};
