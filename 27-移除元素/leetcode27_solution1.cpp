#include "../leetcode.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> v{0, 1, 2, 2, 3, 0, 4, 2};
    cout << solution.removeElement(v, 2) << endl;
    return 0;
}