#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int j = col-1;
        int i = 0;
        while (j>=0 && i<row) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }
//        for (int j = col-1; j>=0; j--) {
//            for (int i=0; i<row; i++) {
//                if (matrix[i][j] == target) {
//                    return true;
//                }
//            }
//        }
        return false;
    }
};

int main()
{
    vector<vector<int>> v1{{1,   4,  7, 11, 15},
                           {2,   5,  8, 12, 19},
                           {3,   6,  9, 16, 22},
                           {10, 13, 14, 17, 24},
                           {18, 21, 23, 26, 30}};
    Solution s = Solution();
    cout << s.findNumberIn2DArray(v1, 11) << endl;
    return 0;
}