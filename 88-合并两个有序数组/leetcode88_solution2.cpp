#include "../leetcode.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = nums1.size() - 1;
        m--;
        n--;

        while (m >= 0 || n >= 0) {
            if (nums1[m] > nums2[n]) swap(nums1[m], nums1[k--]);
            
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    Solution solution = Solution();
    solution.merge(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
