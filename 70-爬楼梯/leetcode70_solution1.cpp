#include "../leetcode.h"

// 递归，超时
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.climbStairs(3) << endl;
    return 0;
}