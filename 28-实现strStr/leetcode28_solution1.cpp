#include "../leetcode.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size();
        int size2 = needle.size();
        if (size2 == 0) return 0;
        if (size1 == 0) return -1;
        for (int i = 0; i < size1 - size2 + 1; i++) {
            if (haystack.substr(i, size2).compare(needle) == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution = Solution();
    string s1 = "hello", s2 = "ll";
    cout << solution.strStr(s1, s2) << endl;
    s1 = "aaaaa";
    s2 = "bba";
    cout << solution.strStr(s1, s2) << endl;

    return 0;
}