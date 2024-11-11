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



            for( int i = 1 ; ; i++ ) {
                int next = num - i*i;
                if( next < 0 ) {
                    break;
                }

                if( visted[next] == false) {
                    
                    // 提前返回的步骤
                    if( next == 0 ) {
                        return step+1;
                    }

                    q.push( make_pair(next, step+1) );
                    visted[next] = true;
                }
            }
        }

        return -1;
    }
};
