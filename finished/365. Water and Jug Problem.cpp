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

// bezout's identity
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (x + y < target) return false;
        return target % gcd(x, y) == 0;
    }
};

class Solution {
    int target;
    unordered_set<int> seen;
    int jug1, jug2;
    bool dfs(int total) {
        if (total == target) return true;
        if (seen.contains(total) or total < 0 or total > jug1 + jug2) return false;
        seen.insert(total);
        return dfs(total + jug1) or dfs(total + jug2) or dfs(total - jug1) or dfs(total - jug2);
    }
public:
    bool canMeasureWater(int x, int y, int target) {
        if (x + y < target) return false;
        this->target = target;
        jug1 = x, jug2 = y;
        return dfs(0);
    }
};