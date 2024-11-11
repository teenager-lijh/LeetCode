class Solution {
public:
    int numSquares(int n) {
        // v, step
        queue<pair<int, int>> q;
        vector<bool> visted(n+1, false);
        q.push( make_pair(n, 0) );

        while( !q.empty() ) {
            pair<int, int> v = q.front();
            q.pop();

            int num = v.first;
            int step = v.second;

            if( num == 0 ) {
                return step;
            }

            for( int i = 1 ; num - i*i >= 0 ; i++ ) {
                int next = num - i*i;
                if( visted[next] == false) {
                    q.push( make_pair(next, step+1) );
                    visted[next] = true;
                }
            }
        }

        return -1;
    }
};
