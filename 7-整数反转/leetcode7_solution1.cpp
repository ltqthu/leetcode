#include <iostream>
using namespace std;

// 123
// 123 % 10 = 3, 123/10 = 12,3
class Solution {
public:
    int reverse(int x) {
        bool positive = (x >= 0) ? true : false;
        if (!positive) x = -x;

        int reverseInt = 0;
        int rem;
        while (x != 0) {
            rem = x % 10;
            x = x / 10;
            reverseInt = 10 * reverseInt + rem;
        }
        return positive ? reverseInt : -reverseInt;
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
