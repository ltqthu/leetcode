#include "../leetcode.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            // 判断
            if (map.count(target - nums[i]) > 0 && i != map[target - nums[i]]) {
                return {i, map[target - nums[i]]};
            }
            // 将元素放入map中
            map[nums[i]] = i;
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
