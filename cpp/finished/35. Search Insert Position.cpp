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
    int searchInsert(vector<int> &nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

// class Solution {
// public:
//     int searchInsert(vector<int> &nums, int target) {
//         const auto N = nums.size();
//         decltype(nums.size()) start = 0, end = N - 1;
//         while (end < N && end >= start) {
//             auto mid = (start + end) / 2;
//             if (nums[mid] > target) {
//                 end = mid - 1;
//             } else if (nums[mid] < target) {
//                 start = mid + 1;
//             } else return mid;
//         }
//         return start;
//     }
// };

// class Solution {
// public:
//     int dig(vector<int> &vec, int head, int tail, int &target) {
//         if (head == tail && vec[head] == target) return head;
//         if (vec[head] < target) return head + 1;
//         if (vec[tail] > target) return tail;
//         if (vec[(head + tail) / 2] == target) return (head + tail) / 2;
//         if (vec[(head + tail) / 2] < target) {
//             return dig(vec, head, (head + tail) / 2 + 1, target);
//         }
//         if (vec[(head + tail) / 2] > target) {
//             return dig(vec, (head + tail) / 2 - 1, tail, target);
//         }
//         return 0;
//     }

//     int searchInsert(vector<int> &nums, int target) {
//         return dig(nums, nums.size() - 1, 0, target);
//     }
// };