#include "../leetcode.h"

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main() {
    Solution solution = Solution();

    return 0;
}
