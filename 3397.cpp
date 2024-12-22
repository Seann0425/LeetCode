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

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
    size_t custom_unique(vector<int> &nums) {
        auto result = 0uz, first = 0uz, last = nums.size();
        while (++first != last) {
            if (nums[result] != nums[first]) swap(nums[++result], nums[first]);
        }
        return ++result;
    }
public:
    int maxDistinctElements(vector<int> &nums, int k) {
        const auto n = nums.size();
        unordered_set<int> freq;
        sort(nums.begin(), nums.end());
        sort(nums.begin() + custom_unique(nums), nums.end());
        auto minimum = numeric_limits<int>::min();
        for (const auto &i : nums) {
            if (!freq.contains(i)) freq.insert(i);
            else {
                auto pointer = max(minimum, i - k);
                while (pointer < i + k && freq.contains(pointer)) pointer++;
                if (pointer <= i + k && !freq.contains(pointer)) freq.insert(pointer);
                minimum = pointer + 1;
            }
        }
        return static_cast<int>(freq.size());
    }
};