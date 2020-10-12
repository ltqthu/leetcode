#include "../leetcode.h"

// 贪心算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return INT_MIN;
        int max_val = nums[0];
        int n = nums.size();
        int sum_val = 0;
        for (int i = 0; i < n; ++i) {
            sum_val += nums[i];
            max_val = max(max_val, sum_val);
            if (sum_val < 0) sum_val = 0;
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
