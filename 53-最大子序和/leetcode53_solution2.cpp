#include "../leetcode.h"

// 动态规划
class Solution {
public:
    int maxSubArray1(vector<int>& nums) {
        int max_val = nums[0];
        int n = nums.size();
        vector<int> dp{nums[0]};
        dp.reserve(n);
        // int dp[n];
        // dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            max_val = max(dp[i], max_val);
        }
        return max_val;
    }

    // 使用数组比vector快
    int maxSubArray2(vector<int>& nums) {
        int max_val = nums[0];
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            max_val = max(dp[i], max_val);
        }
        return max_val;
    }

    // 使用整型
    int maxSubArray3(vector<int>& nums) {
        int max_val = nums[0];
        int n = nums.size();
        int dp = nums[0];
        for (int i = 1; i < n; i++) {
            dp = max(dp + nums[i], nums[i]);
            max_val = max(dp, max_val);
        }
        return max_val;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << solution.maxSubArray1(v) << endl;
    cout << solution.maxSubArray2(v) << endl;
    cout << solution.maxSubArray3(v) << endl;
    return 0;
}
