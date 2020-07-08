#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        while (true) {
            int index = s.find(" ");
            cout << index << endl;
            if (index != -1) {
                s.replace(index, 1, "%20");
            } else {
                break;
            }
        }
        return s;
    }
};

int main() {
    string str = "We are happy.";
    Solution s = Solution();
    cout << s.replaceSpace(str) << endl;
    return 0;
}