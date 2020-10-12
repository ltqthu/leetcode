#include "../leetcode.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

int main() {
    Solution solution = Solution();
    vector<int> v{2, 0, 2, 1, 1, 0};
    solution.sortColors(v);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
