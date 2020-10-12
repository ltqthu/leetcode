#include "../leetcode.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                res = mid;
                break;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // 如果没找到
        if (res == -1) return {-1, -1};
        // 如果找到，向两侧扩散寻找
        int left_res = res;
        int right_res = res;
        while (left_res > 0 || nums[left_res - 1] == target) {
            left_res--;
        }
        while (right_res < nums.size() - 1 || nums[right_res + 1] == target) {
            right_res++;
        }

        return {left_res, right_res};
    }
};

int main() {
    Solution solution = Solution();
    vector<int> v{5, 7, 7, 8, 8, 10};
    int target = 8;
    PrintContainer(solution.searchRange(v, target), "res: ");

    v = {1};
    target = 1;
    PrintContainer(solution.searchRange(v, target), "res: ");

    return 0;
}
