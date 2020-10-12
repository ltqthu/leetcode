#include "../leetcode.h"

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = "1";
        for (int i = 2; i <= n; ++i) {
            int count = 0;
            string res("");
            string str_prev("");
            for (auto &c : s) {
                if (str_prev.empty()) {
                    str_prev.push_back(c);
                    count = 1;
                    continue;
                }
                if (str_prev[0] - c == 0) {
                    count++;
                } else {
                    res += to_string(count) + str_prev;
                    str_prev = c;
                    count = 1;
                }
            }
            res += to_string(count) + str_prev;
            s = res;
        }
        return s;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.countAndSay(6) << endl;
    return 0;
}