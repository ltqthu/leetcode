#include "../leetcode.h"

class Solution {
public:
    int getKthMin(vector<int> &nums1, vector<int> &nums2, int k) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        int index1 = 0, index2 = 0;

        while (true) {
            //边界条件
            if (index1 == size1) {
                return nums2[index2 + k - 1];
            }

            if (index2 == size2) {
                return nums1[index1 + k - 1];
            }

            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            //正常情况
            int newIndex1 = min(index1 + k / 2 - 1, size1 - 1);
            int newIndex2 = min(index2 + k / 2 - 1, size2 - 1);

            if (nums1[newIndex1] <= nums2[newIndex2]) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            } else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }

        return 0;
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int size1 = nums1.size();  // nums1的长度
        int size2 = nums2.size();  // nums2的长度

        if ((size1 + size2) % 2 == 1) {
            return (double)getKthMin(nums1, nums2, (size1 + size2 + 1) / 2);
        } else {
            return (getKthMin(nums1, nums2, (size1 + size2) / 2) + getKthMin(nums1, nums2, (size1 + size2) / 2 + 1)) / 2.0;
        }
    }
};

int main() {
    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};
    Solution s = Solution();
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}
