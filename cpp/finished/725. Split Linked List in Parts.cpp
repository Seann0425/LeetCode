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
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        size_t n = 0, k_parts = k;
        for (ListNode *i = head; i; i = i->next) n++;
        vector<ListNode *> parts(k_parts);
        auto avg = n / k_parts, left = n % k_parts;
        ListNode *cur = head, *prev;
        for (size_t i = 0; cur && i < k_parts; i++) {
            parts[i] = cur;
            for (size_t j = 0; j < avg; j++) {
                prev = cur;
                cur = cur->next;
            }
            if (--left < k_parts) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = nullptr;
        }
        return parts;
    }
};