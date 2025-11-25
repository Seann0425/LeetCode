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
    long long maximumHappinessSum(vector<int> &happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<>());
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            ans += max(0, happiness[i] - i);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////

// class Solution {
// public:
//     long long maximumHappinessSum(vector<int> &happiness, int k) {
//         priority_queue<long long, vector<long long>> children;
//         long long soHappy = 0;
//         for (const auto &h : happiness)
//             children.push(static_cast<long long>(h));
//         for (int i = 0; i < k; i++) {
//             // i means how many children have already been selected
//             long long happy = children.top() - static_cast<long long>(i);
//             soHappy += (happy < 0 ? 0 : happy);
//             children.pop();
//         }
//         return soHappy;
//     }
// };