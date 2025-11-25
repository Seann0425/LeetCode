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
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100005> check_nums;
        for (const auto &num : nums) check_nums.set(static_cast<size_t>(num));

        ListNode root(0, head);
        ListNode* cur = &root, *remove;
        while (cur->next) {
            if (!check_nums.test(static_cast<size_t>(cur->next->val))) {
                cur = cur->next;
                continue;
            }
            remove = cur->next;
            cur->next = remove->next;
            delete remove;
        }
        
        return root.next;
    }
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> check_nums;
        for (const auto &num : nums) check_nums.insert(num);

        ListNode* cur = head;
        //first node
        while (head and check_nums.count(head->val)) {
            cur = head->next;
            delete head;
            head = cur;
        }

        while (cur->next) {
            if (!check_nums.count(cur->next->val)) {
                cur = cur->next;
                continue;
            }
            ListNode* remove = cur->next;
            cur->next = remove->next;
            delete remove;
        }

        return head;
    }
};