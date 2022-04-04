#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


// n 行 n 列， 其中 . 代表空，Q 代表皇后
// 任意两个皇后都不能同行、同列、同对角线 
// -> 共六个方向
// 输出所有合法的解
// 返回一个 vector<vector<string>> 类型的数据
class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);

        return res;
    }

    bool isValid(vector<string>& board, int row, int col){
        // 因为是自上而下一行一行摆放皇后
        // 所以在当前行的下方不存在皇后
        // 则只需要检查此行上方的方向即可

        // 1 检查左上方
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j){
            if(board[i][j] == 'Q')
                return false;
        }

        // 2 检查正上方
        for(int i = row-1; i >= 0 ; --i){
            if(board[i][col] == 'Q')
                return false;
        }

        // 3 检查右上方
        for(int i = row-1, j = col+1; i >= 0 && j < board.size(); --i, ++j){
            if(board[i][j] == 'Q')
                return false;
        }

        return true;

    }

    void backtrack(vector<string>& board, int row){
        if(row >= board.size()){
            // 能够递归到这一层，说明之前的选择都是合法的
            // 则当前 board 纳入到 res 中
            res.push_back(board);
            return;
        }

        // 对于每一层都可以进行这样的选择
        for(int col = 0; col < board.size(); ++col){
            // 做出选择前，对该情况判断是否合法
            // 若不合法则直接跳过
            if(!isValid(board, row, col)) continue;

            // 做出对当前行的选择
            // 并放入到 board 中
            board[row][col] = 'Q';

            // 对下一行进行选择
            backtrack(board, row+1);

            // 撤销当前行的选择
            // 进行下一轮的循环，重新对当前行选择
            board[row][col] = '.';
        }
    }


};



int main()
{
    const int n = 4;

    cout << "N Queens" << endl;

    Solution solution;
    vector<vector<string>> res = solution.solveNQueens(n);

    for(auto solution : res){
        cout << "solution :" << endl;
        for(auto line : solution){
            cout << line << endl;
        }
    }



    return 0;
}