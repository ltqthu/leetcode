#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 1;
        int res = 0;
        unordered_set<char> set;
        set.insert(s[0]);

        for (; left < n; left++) {
            if (left > 0) {
                set.erase(s[left - 1]);
            }
            while (right < n && set.count(s[right]) == 0) {
                set.insert(s[right]);
                right++;
            }
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
