#include "../leetcode.h"

// 双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        // int size = height.size();
        int max_res = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            int area = min(height[i], height[j]) * (j - i);
            if (area > max_res) max_res = area;
            height[i] < height[j] ? i++ : j--;
        }
        return max_res;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> v{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << solution.maxArea(v) << endl;
    return 0;
}