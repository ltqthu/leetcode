#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        bool flag = true;
        int mid = 0;
        if ((n1+n2)%2==1) {
            mid = (n1 + n2)/2 + 1;
        } else {
            mid = (n1 + n2)/2;
        }
        int i = 0, j = 0, count = 0;
        while (i<n1 && j<n2) {
            if (nums1[i] <= num2[j]) {
                i++;
            } else {
                j++;
            }
            count++;
            if (count == mid) {
                if 
        }



    }
};

int main() {
    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};
    Solution s = Solution();
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}

