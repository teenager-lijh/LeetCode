//
// Created by 李嘉豪 on 2022/10/9.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int id = logs[0][0];
        int time_max = logs[0][1];

        for(int i = 1 ; i < logs.size() ; ++i) {
            if(logs[i][1] - logs[i-1][1] > time_max) {
                id = logs[i][0];
                time_max = logs[i][1] - logs[i-1][1];
            }
            else if(logs[i][1] - logs[i-1][1] == time_max && logs[i][0] < id) {
                id = logs[i][0];
            }
        }

        return id;
    }
};

int main() {




    return 0;
}