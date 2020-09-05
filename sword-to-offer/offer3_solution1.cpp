/*
 * @Description: 
 * @Author: liutq
 * @Date: 2020-09-05 21:54:23
 * @LastEditTime: 2020-09-05 23:08:05
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for ( int i=1; i<nums.size(); i++ ) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
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
