#include "../leetcode.h"

// 两层遍历，暴力方法（超时）
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int max_res = 0;
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                int area = min(height[i], height[j]) * (j - i);

                if (area > max_res) {
                    max_res = area;
                }
            }
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