// 搜索
class Solution {
public:

    int direction[4][2] = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), false));
        
        for( int i = 0 ; i < board.size() ; i++ ) {
            for( int j = 0 ; j < board[0].size() ; j++ ) {
                visited[i][j] = true;
                if(findWord(board, word, i, j, 0, visited)) {
                    return true;
                }
                visited[i][j] = false;
            }
        }

        return false;
    }

    bool findWord(vector<vector<char>>& board, string& word, int x, int y, int s, vector<vector<int>>& visited) {
        if(board[x][y] == word[s] && (s+1) >= word.size()) return true;
        if(board[x][y] != word[s]) return false;

        for( int i = 0 ; i < 4 ; i++ ) {
            int newX = x + direction[i][0];
            int newY = y + direction[i][1];

            if(newX >= board.size() || newX < 0 || newY >= board[0].size() || newY < 0) continue;
            if(visited[newX][newY]) continue;

            visited[newX][newY] = true;
            if(findWord(board, word, newX, newY, s+1, visited)) return true;
            visited[newX][newY] = false;
        }

        return false;
    }
};
