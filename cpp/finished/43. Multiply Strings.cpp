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
    string multiply(string num1, string num2) {
        const auto M = num1.size();
        const auto N = num2.size();
        string ans;
        ans.resize(M + N, '0');
        for (size_t j = N - 1; j < N; j--) {
            int carry = 0;
            for (size_t i = M - 1; i < M; i--) {
                auto tmp = (num1[i] - '0') * (num2[j] - '0') + carry;
                size_t target = i + j + 1;
                auto origin = ans[target] - '0';
                origin += tmp;
                carry = origin / 10;
                origin %= 10;
                ans[target] = ('0' + origin);
            }
            if (carry) ans[j] = carry + '0';
        }
        while (ans.size() > 1 && ans.front() == '0')
            ans.erase(ans.begin());
        return ans;
    }
};