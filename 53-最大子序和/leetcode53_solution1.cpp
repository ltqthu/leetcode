#include "../leetcode.h"

// 暴力法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_val = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum_val = 0;
            for (int j = i; j < n; j++) {
                sum_val += nums[j];
                max_val = sum_val > max_val ? sum_val : max_val;
            }
        }
        return max_val;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << solution.maxSubArray(v) << endl;
    return 0;
}
