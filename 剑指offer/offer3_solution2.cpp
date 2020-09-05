#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> set;
        for ( int i=0; i<nums.size(); i++ ) {
            if (set.count(nums[i]) == 0) {
                set.insert(nums[i]);
            } else {
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
