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
    enum Operator { Add, Sub, Mul };
    vector<int> ans, nums;
    vector<Operator> ops;
    inline int cal(int a, int b, Operator o) {
        if (o == Add) return a + b;
        if (o == Sub) return a - b;
        return a * b;
    }
    void compute(size_t left, size_t right, vector<int> &dest) {
        if (left == right) {
            dest.push_back(nums[left]);
            return;
        }
        for (size_t i = left; i < right; i++) {
            vector<int> lval, rval;
            compute(left, i, lval);
            compute(i + 1, right, rval);
            for (const auto &l : lval)
                for (const auto &r : rval) dest.emplace_back(cal(l, r, ops[i]));
        }
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        int tmp = 0;
        for (const auto &c : expression) {
            if (isdigit(c)) {
                tmp = tmp * 10 + (c - '0');
                continue;
            }
            nums.push_back(tmp);
            tmp = 0;
            if (c == '+') ops.emplace_back(Add);
            else if (c == '-') ops.emplace_back(Sub);
            else if (c == '*') ops.emplace_back(Mul);
        }
        nums.push_back(tmp);

        compute(0, nums.size() - 1, ans);
        return ans;
    }
};