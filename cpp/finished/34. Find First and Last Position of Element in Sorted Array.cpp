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

class Node {
public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/*the solution should start from below*/

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto __ = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (!binary_search(nums.begin(), nums.end(), target)) return {-1, -1};
        auto tmp = equal_range(nums.begin(), nums.end(), target);
        return {static_cast<int>(tmp.first - nums.begin()), static_cast<int>(tmp.second - nums.begin() - 1)};
    }
};

////////////////////////////////////////////////////////////////

// class Solution {
// public:
//     vector<int> searchRange(vector<int> &nums, int target) {
//         vector<int> result = {-1, -1};
//         int left = binarySearch(nums, target, true);
//         int right = binarySearch(nums, target, false);
//         result[0] = left;
//         result[1] = right;
//         return result;
//     }

//     int binarySearch(vector<int> &nums, int target, bool isSearchingLeft) {
//         int left = 0;
//         int right = nums.size() - 1;
//         int idx = -1;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;

//             if (nums[mid] > target) {
//                 right = mid - 1;
//             } else if (nums[mid] < target) {
//                 left = mid + 1;
//             } else {
//                 idx = mid;
//                 if (isSearchingLeft) {
//                     right = mid - 1;
//                 } else {
//                     left = mid + 1;
//                 }
//             }
//         }

//         return idx;
//     }
// };