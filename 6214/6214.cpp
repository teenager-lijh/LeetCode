#include <string>
#include <vector>
#include <algorithm>

using  namespace std;
//输入：event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
//输出：true
//解释：两个事件的交集从 01:20 开始，到 02:00 结束。

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
       string start_time_one = event1[0];
       string end_time_one = event1[1];

       string start_time_two = event2[0];
       string end_time_two = event2[1];

       // 事件 2 的开始时间或者结束时间位于 事件 1 中的情况
       if(start_time_two >= start_time_one && start_time_two <= end_time_one)
           return true;

       if(end_time_two >= start_time_one && end_time_two <= end_time_one)
           return true;

        // 事件 1 的开始时间或者结束时间位于 事件 2 中的情况
       if(start_time_one >= start_time_two && start_time_one <= end_time_two)
           return true;

       if(end_time_one >= start_time_two && end_time_one <= end_time_two)
           return true;

        // 事件 1 包裹事件 2
       if(start_time_one < start_time_two && end_time_one > end_time_two)
           return true;

       // 事件 2 包裹事件 1
       if(start_time_two < start_time_one && end_time_two > end_time_one)
           return true;

       return false;
    }
};

int main()
{


    return 0;
}
