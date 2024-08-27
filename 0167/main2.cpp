class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 2 对撞指针 O(N)
        // numbers[0...i) 搜索过的区间
        // numbers(i...numbers.size()-1] 二分查找的区间

        vector<int> res;
        
        int i = 0, j = numbers.size() - 1;

        // 不能是同一个元素
        while( i < j ) {
            if( numbers[i] + numbers[j] == target) {
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            } else if( numbers[i] + numbers[j] < target ) {
                i++;
            } else {
                j--;
            }
        }


        res.push_back(0);
        res.push_back(0);
        return res;

    }
};
