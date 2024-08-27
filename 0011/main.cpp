class Solution {
public:
    int maxArea(vector<int>& height) {
            int i = 0, j = height.size() - 1;

            int maxContainer = -1;

            while( i < j ) {
                // 只用一边乘 是一样的
                int container = min(height[i], height[j]) * (j-i);

                if(container > maxContainer) {
                    maxContainer = container;
                }

                if(height[i] < height[j]) i++;
                else j--;

            }

            return maxContainer;
    }
};
