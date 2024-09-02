#include <iostream>
#include <set>
using namespace std;


class Solution {
public:
    bool isHappy(int n) {
        set<int> record;

        int sum = 0;

        record.insert( n );

        while( true ) {

            // 给定整数 n 遍历 n 的所有位的平方
            while( n > 0 ) {
                int v = n % 10;
                sum += v * v;
                n /= 10;
            }

            if( record.find( sum ) != record.end() && sum != 1 ) return false;

            if( sum == 1 ) return true;

            record.insert( sum );
            n = sum;
            sum = 0;
        }

        return true;
    }
};


int main() {
    Solution solution;
    int n = 1;
    bool res = solution.isHappy(n);
    cout << res << endl;
    return 0;
}
