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

class Solution {
public:
    int subarraysWithKDistinct(vector<int> &nums, int k) {
        int sub_with_max_element_k = subarray_with_atmost_k(nums, k);
        int reduced_sub_with_max_k = subarray_with_atmost_k(nums, k - 1);
        return (sub_with_max_element_k - reduced_sub_with_max_k);
    }
    int subarray_with_atmost_k(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        int left = 0, right = 0, ans = 0;
        while (right < nums.size()) {
            map[nums[right]]++;
            while (map.size() > k) {
                map[nums[left]]--;
                if (map[nums[left]] == 0) map.erase(nums[left]);
                left++;
            }
            ans += right - left + 1; // basically the size of subarray;
            right++;
        }
        return ans;
    }
};