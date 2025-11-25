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
    vector<int> ans;
    size_t size;
    bool found = false;
    int n;
    bitset<25> visited{};
    void backtracking(size_t i) {
        if (found) return;
        if (i == size) {
            found = true;
            return;
        }
        if (ans[i]) {
            backtracking(i + 1);
            return;
        }
        for (auto j = n; j; j--) {
            if (visited[j]) continue;
            if (j == 1) {
                visited[j] = true;
                ans[i] = j;
                backtracking(i + 1);
                if (found) return;
                ans[i] = 0;
                visited[j] = false;
            } else {
                if (i + j >= size or ans[i + j]) continue;
                ans[i] = j;
                ans[i + j] = j;
                visited[j] = true;
                backtracking(i + 1);
                if (found) return;
                ans[i] = 0;
                ans[i + j] = 0;
                visited[j] = false;
            }
        }
    }
public:
    vector<int> constructDistancedSequence(int n) {
        size = 2 * n - 1;
        ans.assign(size, 0);
        this->n = n;
        backtracking(0uz);
        return ans;
    }
};