class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        bool ok = false;
        int maxdis = 1000;
        int minimum = maxdis;

        vector<vector<string>> result;
        unordered_map<string, bool> visited;
        // 记录距离 beginWord 的距离
        unordered_map<string, int> dis;
        for( int i = 0 ; i < wordList.size() ; i++ ) {
            if( wordList[i] == endWord ) {
                ok = true;
                visited[wordList[i]] = false;
                dis[wordList[i]] = maxdis;
            } else if(wordList[i] == beginWord ) {
                continue;
            } else {
                visited[wordList[i]] = false;
                dis[wordList[i]] = maxdis;
            }

        }

        if(!ok) {
            return result;
        }

        // 记录从哪个节点过来的
        unordered_map<string, vector<string>> record;


        // word && step
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

                    if(visited.find(next) != visited.end() && (!visited[next] || step <= dis[next])) {
                        dis[next] = step;
                        bool flag = true;
                        for( int k = 0 ; k < record[next].size() ; k++ ) {
                            if( record[next][k] == word ) {
                                flag = false;
                            }
                        }

                        if(flag) {
                            record[next].push_back(word);
                            q.push(make_pair(next, step+1));
                            visited[next] = true;
                        }
                    }
                }
            }
        }

//        for(auto iter = record.begin() ; iter !=  record.end() ; iter++ ) {
//            auto line = iter->second;
//            cout << iter->first << " : ";
//            for( int i = 0 ; i < line.size() ; i++ ) {
//                cout << line[i] << " ";
//            }
//            cout << endl;
//        }

        vector<string> ss;
        ss.push_back(endWord);
        dfs(record, result, beginWord, ss);

        return result;
    }

    void dfs(unordered_map<string, vector<string>>& record, vector<vector<string>>& result, string beginWord, vector<string>& s) {
        string word = s[s.size()-1];
        if( word == beginWord ) {
            vector<string> res = s;
            for( int i = 0 ; i < res.size() / 2 ; i++ ) {
                swap(res[i], res[res.size()-1-i]);
            }
            result.push_back(res);
        }

        for( int i = 0 ; i < record[word].size() ; i++ ) {
            s.push_back(record[word][i]);
            dfs(record, result, beginWord, s);
            s.pop_back();
        }
    }
};
