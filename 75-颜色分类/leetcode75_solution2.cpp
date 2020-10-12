#include "../leetcode.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0;
        int p2 = n - 1;
        for (int i = 0, j = n - 1; i < j; i++) {
            if (nums[i] == 2 && nums[j] != 2) {
                swap(nums[i], nums[j]);
                j--;
            }
        }
    }
};

int main() {
    Solution solution = Solution();
    vector<int> v{2, 0, 2, 1, 0, 1, 1, 0};
    solution.sortColors(v);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
