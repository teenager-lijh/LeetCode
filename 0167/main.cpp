class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 1 二分搜索优化 : O(NlogN)
        // numbers[0...i) 搜索过的区间
        // numbers(i...numbers.size()-1] 二分查找的区间

        vector<int> res;

        for( int i = 0 ; i < numbers.size() ; i++ ) {
            int v = numbers[i];

            int l = i+1, r = numbers.size() - 1;
            while( l <= r ) {
                int mid = (l+r) / 2;
                if( numbers[mid] + v == target ) {
                    res.push_back(i+1);
                    res.push_back(mid+1);
                    return res;
                } else if( numbers[mid] + v < target ) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        res.push_back(0);
        res.push_back(0);
        return res;

    }
};
