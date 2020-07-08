#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            while (i != nums[i]) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                } else {
                    // swap(nums[i], nums[nums[i]]);
                    int temp = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> v1{2, 3, 1, 0, 2, 5, 3};
    Solution s = Solution();
    cout << s.findRepeatNumber(v1) << endl;
    return 0;
}
