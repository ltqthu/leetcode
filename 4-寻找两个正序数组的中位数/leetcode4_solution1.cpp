#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();  // nums1的长度
        int n2 = nums2.size();  // nums2的长度
    };

    int main() {
        vector<int> nums1{1, 2};
        vector<int> nums2{3, 4};
        Solution s = Solution();
        cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    }
