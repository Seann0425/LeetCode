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

#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>
#ifndef DEBUG
#define DEBUG
template <typename T>
void debug(const vector<T> &v) {
    if (v.empty()) {
        cout << "[]"s << endl;
        return;
    }
    cout << '[' << v.front();
    for (const auto &x : v | views::drop(1)) cout << ',' << x;
    cout << "]" << endl;
}
void debug(const string &s) { cout << '"' << s << '"' << endl; }
#endif

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int maxJump(vector<int> &stones) {
        // 首先題目本身可以看成兩隻青蛙分別從起點跳到終點，但中間不能使用同樣的石頭
        // 對於任意中間的石頭，假設有frog1 frog2 frog2 frog1這樣的排列
        // 把他換成frog1 frog2 frog1 frog2，永遠不會原本的解更差
        // 所以兩隻青蛙應該交替使用石頭
        // 另外比較trivial的，如果某個石頭沒有被使用到，那麼把他加到其中一隻青蛙的跳躍中，不會讓解更差
        // 所以應該有一組最佳解使用了所有石頭
        const auto n = stones.size();
        auto ans = stones[1] - stones[0]; // for stones.size() == 2
        for (auto i = 2uz; i < n; ++i) ans = max(ans, stones[i] - stones[i - 2]);
        return ans;
    }
};