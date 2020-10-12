#include "../leetcode.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& v1, vector<int>& v2) {
                 if (v1[0] == v2[0]) return v1[1] < v2[1];
                 return v1[0] < v2[0];
             });

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= res.back()[1]) {
                if (intervals[i][1] > res.back()[1]) {
                    res.back()[1] = intervals[i][1];
                }
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution solution = Solution();
    vector<vector<int>> v{{1, 3}, {2, 4}, {8, 10}, {9, 11}};
    v = {{1, 4}, {2, 3}};
    vector<vector<int>> res = solution.merge(v);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    return 0;
}
