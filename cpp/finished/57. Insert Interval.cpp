#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

/*the solution should start from below*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        if (intervals.size() == 0) return {newInterval};
        vector<vector<int>> ans;
        int newStart = newInterval[0], newEnd = newInterval[1];
        bool flag = false;
        bool inserted = false;
        for (const auto &interval : intervals) {
            if (!flag) {
                if (newInterval[1] < interval[0]) {
                    ans.push_back(newInterval);
                    ans.push_back(interval);
                    flag = true;
                    inserted = true;
                    continue;
                }
                if (interval[1] < newInterval[0]) {
                    ans.push_back(interval);
                    continue;
                } else if (interval[1] >= newInterval[0]) {
                    newStart = min(interval[0], newInterval[0]);
                    flag = true;
                    if (interval[1] > newInterval[1]) {
                        newEnd = interval[1];
                        ans.push_back({newStart, newEnd});
                        inserted = true;
                    }
                }
            } else {
                if (inserted) {
                    ans.push_back(interval);
                    continue;
                } else if (interval[0] > newInterval[1]) {
                    newEnd = newInterval[1];
                    ans.push_back({newStart, newEnd});
                    ans.push_back(interval);
                    inserted = true;
                } else if (newInterval[1] <= interval[1]) {
                    newEnd = interval[1];
                    ans.push_back({newStart, newEnd});
                    inserted = true;
                }
            }
        }
        if (!inserted) ans.push_back({newStart, newEnd});
        return ans;
    }
};