#include "../leetcode.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0 || target < nums[0] || target > nums[n - 1]) return -1;

        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 7;
    cout << solution.search(nums, target) << endl;
    nums = {5};
    cout << solution.search(nums, 5) << endl;

    return 0;
}
