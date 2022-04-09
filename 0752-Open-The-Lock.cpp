#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


class Solution {
public:

    // 用于标记某个节点是否被访问过
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
        // 数组整个都初始化为 0 就代表了是 false
        memset(visited, 0, sizeof(visited));

        // 在 visited 中初始化不可达的顶点
        // 遍历 deadends 中的每一个密码状态
        // 把这些节点都标记为已经入队过
        // 其实就是在说，这些结果不能够再被访问了
        // 因为 BFS 每次都是从队列中取一个节点来访问
        // 不能够入队就代表了不会从队列中被访问
        for(auto s : deadends) {
            visite(s);
        }

        // 极端情况的考虑
        // 如果 deadends 中存在 0000
        // 又由于我们密码锁的初始状态就是 0000
        // 所以我们无法从 0000 访问到任何节点
        // 则程序返回 -1 表示无解
        if(isVisted(string("0000")))
            return -1;
            
        // step 记录的是
        // 当前正在遍历的这些节点
        // 从 0000 状态开始
        // 最少需要拨动几次才能够触达
        // 初始化为拨动 0 次
        // 因为 0000 状态不需要拨动
        // 0000 状态就是最初始的状态
        int step = 0;

        // 用 start 字符串记录初始状态 0000
        string start = "0000";
        
        // BFS 用到的辅助队列 q
        queue<string> q;

        // 让初始状态入队
        q.push(start);

        // 并且标记该状态已经入队过了
        visite(start);

        // 队列不为空则 BFS 未结束
        while(!q.empty()) {
            // 通过 size 可以知道当前遍历的那一层有多少个节点
            // 每遍历完成 size 个节点后
            // step 就应该增加 1 
            int sz = q.size();

            for(int i = 0 ; i < sz ; ++i) {
                // 从队头取一个节点出来
                string cur = q.front();
                // 并且删除队头节点
                q.pop();

                // 判断是否是目标 target
                if(cur == target)
                    return step;

                // BFS 的套路
                // 添加相邻节点
                // 只不过这里的相邻节点需要自己来构建
                // 共有 4 个拨轮
                // 每个拨轮可以向上或向下两种拨动方式
                for(int j = 0 ; j < 4 ; ++j) {
                    string plus_cur = plusOne(cur, j);
                    // 入队之前要保证此节点没有被入队过
                    if(!isVisted(plus_cur)) {
                        q.push(plus_cur);
                        // 入队后标记此节点已经入队过了
                        visite(plus_cur);
                    }

                    string minus_cur = minusOne(cur, j);
                    // 入队之前要保证此节点没有被入队过
                    if(!isVisted(minus_cur)) {
                        q.push(minus_cur);
                        // 入队后标记此节点已经入队过了
                        visite(minus_cur);
                    }
                }

            }

            // 维护 step 变量
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