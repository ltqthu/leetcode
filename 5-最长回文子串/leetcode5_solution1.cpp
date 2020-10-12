#include "../leetcode.h"

// 暴力方法
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }
        string strRes;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                // 判断是否是回文串
                if (j - i + 1 > max_len && isPalindrome(s.substr(i, j - i + 1))) {
                    strRes = s.substr(i, j - i + 1);
                    max_len = j - i + 1;
                }
            }
        }
        return strRes;
    }
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
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

    str = "ac";
    cout << solution.longestPalindrome(str) << endl;
    return 0;
}