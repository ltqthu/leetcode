#include "../leetcode.h"

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        unordered_map<char, char> pairs{{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> stk;
        for (auto ch : s) {
            if (pairs.count(ch) != 0) {                       // 如果是右括号
                if (stk.empty() || stk.top() != pairs[ch]) {  //如果不匹配
                    return false;
                } else {
                    stk.pop();
                }

            } else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

int main() {
    Solution solution = Solution();

    string str = "()[]{}";
    cout << solution.isValid(str) << endl;

    str = "([)]";
    cout << solution.isValid(str) << endl;

    str = "((";
    cout << solution.isValid(str) << endl;
}