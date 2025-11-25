#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

// O(n^2) is faster in this case
#include <ranges>
class Solution {
public:
    bool checkIfExist(vector<int> &arr) {
        for (const auto [i, little] : std::views::enumerate(arr)) {
            for (const auto [j, great] : std::views::enumerate(arr)) {
                if (i == j) continue;
                if (little * 2 == great) return true;
            }
        }
        return false;
    }
};

// #include <ranges>
// class Solution {
// public:
//     bool checkIfExist(vector<int> &arr) {
//         unordered_set<int> seen;
//         sort(arr.begin(), arr.end(), greater<int>());
//         for (const auto &i : arr) {
//             if (seen.contains(i * 2)) return true;
//             seen.insert(i);
//         }
//         seen.clear();
//         for (const auto &i : arr | std::views::reverse) {
//             if (seen.contains(i * 2)) return true;
//             seen.insert(i);
//         }
//         return false;
//     }
// };