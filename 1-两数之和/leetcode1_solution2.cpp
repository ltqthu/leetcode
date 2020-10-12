#include "../leetcode.h"

// 两遍哈希
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;  //<nums的值，下标>
        // 一遍哈希建立映射
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        // 两遍哈希寻找
        for (int i = 0; i < nums.size(); i++) {
            // 如果存在想要的值，并且元素没有重复
            if (map.count(target - nums[i]) > 0 && i != map[target - nums[i]]) {
                return {i, map[target - nums[i]]};
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums{3, 2, 4};
    int target = 6;
    Solution s = Solution();
    vector<int> vRes = s.twoSum(nums, target);

    for (int i = 0; i < vRes.size(); ++i) {
        cout << vRes[i] << endl;
    }

    return 0;
}
