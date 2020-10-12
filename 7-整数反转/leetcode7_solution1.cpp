#include "../leetcode.h"

// 123
// 123 % 10 = 3, 123/10 = 12
class Solution {
public:
    int reverse(int x) {
        int rem, res = 0;
        while (x != 0) {
            rem = x % 10;
            x = x / 10;
            // res = 10 * res + rem >= max
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && rem > 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && rem < -8)) {
                return 0;
            }
            res = 10 * res + rem;
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    int x1 = 123;
    cout << s.reverse(x1) << endl;
    int x2 = -234;
    cout << s.reverse(x2) << endl;
    int x3 = 0;
    cout << s.reverse(x3) << endl;
    cout << INT_MAX << endl;

    return 0;
}
