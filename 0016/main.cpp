class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 对撞指针

        // 排序
        sort(nums.begin(), nums.end());

        int sum = nums[0] + nums[nums.size()-2] + nums[nums.size()-1];

        // 搜索
        for( int k = 0 ; k <= nums.size() - 3 ; k++ ) {
            
            int i = k+1, j = nums.size() - 1;

            while( i < j ) {
                if( abs(nums[k] + nums[i] + nums[j] - target) < abs(sum - target) ) {
                    sum = nums[k] + nums[i] + nums[j];
                } 
                
                if( nums[k] + nums[i] + nums[j] > target ) {
                    j--;
                } else {
                    i++;
                }
            }
        }

        return sum;
        
    }
};
