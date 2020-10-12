#include "../leetcode.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int add = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] + add <= 9) {
                digits[i] += add;
                break;
            } else {
            }
        }
    }
};

int main() {
    Solution solution = Solution();

    return 0;
}
