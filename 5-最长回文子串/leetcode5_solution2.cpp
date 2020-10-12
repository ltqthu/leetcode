#include "../leetcode.h"

// 动态规划法
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        string res;
        int max_len = 1;
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        for (int len = 1; len <= size; len++) {
            for (int i = 0; i + len - 1 < size; i++) {
                int j = i + len - 1;
                if (len == 1) {
                    dp[i][j] = true;
                } else if (len == 2) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (len > max_len && dp[i][j]) {
                    res = s.substr(i, len);
                    max_len = len;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution = Solution();
    string str = "babad";

    cout << solution.longestPalindrome(str) << endl;

    str = "ababababa";
    cout << solution.longestPalindrome(str) << endl;

    str = "a";
    cout << solution.longestPalindrome(str) << endl;
    return 0;
}