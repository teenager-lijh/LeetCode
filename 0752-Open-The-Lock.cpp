#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


class Solution {
public:

    bool visited[10][10][10][10];

    void visite(string s) {
        unsigned int s0 = s[0] - '0';
        unsigned int s1 = s[1] - '0';
        unsigned int s2 = s[2] - '0';
        unsigned int s3 = s[3] - '0';

        // cout << "visite : " << s << endl;

        visited[s0][s1][s2][s3] = true;
    }

    bool isVisted(string s) {
        unsigned int s0 = s[0] - '0';
        unsigned int s1 = s[1] - '0';
        unsigned int s2 = s[2] - '0';
        unsigned int s3 = s[3] - '0';
        // cout << "s : " << s << " bool : " << visited[s0][s1][s2][s3] << endl;
        return visited[s0][s1][s2][s3];
    }

    // s[j] 向上拨动一次
    string plusOne(string s, int j) {
        if(s[j] == '9')
            s[j] = '0';
        else
            s[j] += 1;

        return s;
    }

    // s[j] 向下拨动一次
    string minusOne(string s, int j) {
        if(s[j] == '0')
            s[j] = '9';
        else
            s[j] -= 1;

        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        // 每个节点的相邻节点有 8 个
    
        // 初始化为每个节点都没有访问过
        memset(visited, 0, sizeof(visited));

        // 在 visited 中初始化不可达的顶点
        for(auto s : deadends) {
            visite(s);
        }

        if(isVisted(string("0000")))
            return -1;
            
        // 初始化为拨动 0 次
        int step = 0;
        string start = "0000";
        
        queue<string> q;
        q.push(start);
        visite(start);

        while(!q.empty()) {
            int sz = q.size();

            for(int i = 0 ; i < sz ; ++i) {
                string cur = q.front();
                q.pop();

                // cout << "cur : " << cur << endl;

                // 判断是否是目标 target
                if(cur == target)
                    return step;

                // BFS 的套路
                // 添加相邻节点
                // 只不过这里的相邻节点需要自己来构建
                // 共有 4 个拨轮
                // 每个拨轮可以向上或向下两种拨动方式
                for(int j = 0 ; j < 4 ; ++j) {
                    // cout << "for 4 " << "j : " << j << endl;
                    string plus_cur = plusOne(cur, j);
                    if(!isVisted(plus_cur)) {
                        q.push(plus_cur);
                        visite(plus_cur);
                    }

                    string minus_cur = minusOne(cur, j);
                    if(!isVisted(minus_cur)) {
                        q.push(minus_cur);
                        visite(minus_cur);
                    }
                }

            }

            step += 1;
        }

        // 整个 BFS 结束后还没有找到解
        // 则不可达
        return -1;
    }
};




int main() {

    vector<string> deadends = {
        "0000"
    };

    string target = "8888";
    
    Solution solution;
    int res = solution.openLock(deadends, target);

    cout << "res : " << res << endl;


    return 0;
}