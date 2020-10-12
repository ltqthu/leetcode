#include "../leetcode.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return x == rev || x == rev / 10;
    }
};

int main() {
    Solution s = Solution();
    int x1 = 121;
    cout << s.isPalindrome(x1) << endl;
    int x2 = 0;
    cout << s.isPalindrome(x2) << endl;
    int x3 = 10;
    cout << s.isPalindrome(x3) << endl;
    return 0;
}
