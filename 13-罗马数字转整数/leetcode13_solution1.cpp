#include "../leetcode.h"

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman_map{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (roman_map[s[i]] < roman_map[s[i + 1]]) {
                sum -= roman_map[s[i]];
            } else {
                sum += roman_map[s[i]];
            }
        }
        sum += roman_map[s.back()];
        return sum;
    }
};

int main() {
    Solution s = Solution();
    cout << s.romanToInt("III") << endl;

    cout << s.romanToInt("IV") << endl;
    cout << s.romanToInt("LVIII") << endl;

    return 0;
}
