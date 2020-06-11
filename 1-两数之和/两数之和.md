
>给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的那 **两个** 整数，并返回他们的数组下标。
>你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
>
>示例:
>
>给定 `nums = [2, 7, 11, 15], target = 9`
>
>因为 `nums[0] + nums[1] = 2 + 7 = 9`
>所以返回 `[0, 1]`

# 暴力

```cpp
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
```



# 两遍哈希

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.count(target-nums[i]) > 0 && i != map[target-nums[i]] )
            {
                return { i, map[target - nums[i]] };
            }
        }
        return {};
    }
};
```

# 一遍哈希

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.count(target - nums[i]) > 0 && i != map[target - nums[i]])
            {
                return { i, map[target - nums[i]] };
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
```



# 测试程序

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// class Solution;

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
```







参考：

> https://leetcode-cn.com/problems/two-sum