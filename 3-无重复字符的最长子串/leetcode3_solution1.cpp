#include "../leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int n = s.size();
        int right = 1;
        int res = 0;
        unordered_set<char> hash;
        hash.insert(s[0]);

        for (int left = 0; left < n; left++) {
            if (left > 0) {
                hash.erase(s[left - 1]);
            }
            while (right < n && hash.count(s[right]) == 0) {
                hash.insert(s[right]);
                right++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    string str = "abcabdcbb";
    cout << s.lengthOfLongestSubstring(str) << endl;

    string str2 = "bbbb";
    cout << s.lengthOfLongestSubstring(str2) << endl;

    return 0;
}
