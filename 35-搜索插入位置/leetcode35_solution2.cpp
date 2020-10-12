#include "../leetcode.h"

// 二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;
        if (target < nums[0]) return 0;
        if (nums[n - 1] < target) return n;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> v{1, 3, 5, 6};
    cout << solution.searchInsert(v, 5) << endl;
    return 0;
}