#include "../leetcode.h"

class Solution {
public:
    unordered_map<string, vector<string>> table{
        {"start", {"start", "sign", "number", "end"}},
        {"sign", {"end", "end", "number", "end"}},
        {"number", {"end", "end", "number", "end"}},
        {"end", {"end", "end", "end", "end"}}};
    int get_state(char ch) {
        if (isspace(ch)) return 0;
        if (ch == '+' || ch == '-') return 1;
        if (isdigit(ch)) return 2;
        return 3;
    }
    int myAtoi(string str) {
        int sign = 1;
        string state = "start";
        long res = 0;
        for (char ch : str) {
            state = table[state][get_state(ch)];
            if (state == "start") continue;
            if (state == "sign") {
                sign += ch == '-' ? -2 : 0;
                continue;
            }
            if (state == "number") {
                res = res * 10 + ch - '0';
                if (sign * res > INT_MAX) return INT_MAX;
                if (sign * res < INT_MIN) return INT_MIN;
                continue;
            }
            if (state == "end") break;
        }
        return (int)sign * res;
    }
};

int main() {
    Solution solution = Solution();
    string str;
    str = "  +42 ";
    cout << solution.myAtoi(str) << endl;

    str = "42";
    cout << solution.myAtoi(str) << endl;

    str = "-91283472332";
    cout << solution.myAtoi(str) << endl;

    return 0;
}