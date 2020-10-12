#include "../leetcode.h"

// 简单思想
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (target < nums[0]) return 0;
        if (target > nums[len - 1]) return len;
        if (target == nums[len - 1]) return len - 1;
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] < target && target < nums[i + 1]) return i + 1;
            if (nums[i] == target) return i;
        }
        return -1;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> v{1, 3, 5, 6};
    cout << solution.searchInsert(v, 5) << endl;
    return 0;
}