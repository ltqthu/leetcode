#include "../leetcode.h"
// 暴力
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size()-1; ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i]+nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums{3,2,4};
    int target = 6;
    Solution s = Solution();
    vector<int> vRes = s.twoSum(nums, target);

    for (int i = 0; i < vRes.size(); ++i) {
        cout << vRes[i] << endl;
    }

    return 0;
}
