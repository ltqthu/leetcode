#include "../leetcode.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() < 3 || numRows == 1) {
            return s;
        }
        int len = min((int)s.size(), numRows);
        vector<string> vec(len, "");
        bool flag = false;
        int index = 0;
        for (char ch : s) {
            vec[index] += ch;
            if (index == 0 || index == len - 1) {
                flag = !flag;
            }
            index += flag ? 1 : -1;
        }
        string res;
        for (string str : vec) {
            res += str;
        }
        return res;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.convert("LEETCODEISHIRING", 3) << endl;
    return 0;
}