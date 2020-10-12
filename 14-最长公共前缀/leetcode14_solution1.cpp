#include "../leetcode.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string str_prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            str_prefix = longestCommonPrefix(str_prefix, strs[i]);
            if (str_prefix.empty()) return "";
        }
        return str_prefix;
    }

    string longestCommonPrefix(string str1, string str2) {
        int len = min(str1.size(), str2.size());
        int index;
        for (int i = 0; i < len; i++) {
            if (str1[i] != str2[i]) {
                return str1.substr(0, i);
            }
        }
        return str1.size() > str2.size() ? str2 : str1;
    }
};

int main() {
    Solution s = Solution();
    vector<string> v1{"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(v1) << endl;
    vector<string> v2{"dog", "racecar", "car"};
    cout << s.longestCommonPrefix(v2) << endl;

    return 0;
}
