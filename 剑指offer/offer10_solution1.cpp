#include <iostream>
using namespace std;


class Solution {
public:
    int fib(int n) {
        if (n<2) {
            return n;
        }
        int f0 = 0, f1 = 1;
        for(int i=2; i<=n; i++) {
            int temp = f1;
            f1 = f0 + f1;
            f0 = temp;
        }
        return f1;
    }
};





int main() {
    Solution s = Solution();
    cout << s.fib(5) << endl;
    return 0;
}