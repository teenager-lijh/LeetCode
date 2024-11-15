// 排列不重复的关键是
// 如果当前选定的元素的前面没有发生变化
// 那么值相同的元素只能在当前位置使用一次
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> cur;

        findPermuteUnique(nums, cur, 0, visited, res);

        return res;
    }

    void findPermuteUnique(vector<int>& nums, vector<int>& cur, int index, vector<bool>& visited, vector<vector<int>>& res) {
        if( index >= nums.size() ) {
            res.push_back(cur);
            return;
        }

        // -10 <= nums[i] <= 10
        vector<bool> isUsedValue(21, false);
        
        for( int i = 0 ; i < nums.size() ; i++ ) {
            if( visited[i] == false &&  !isUsedValue[nums[i]+10] ) {
                isUsedValue[nums[i]+10] = true;
                visited[i] = true;
                cur.push_back(nums[i]);
                
                findPermuteUnique(nums, cur, index+1, visited, res);
                
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
};
