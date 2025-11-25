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
    array<int, 5> direc{0, -1, 0, 1, 0};
public:
    int slidingPuzzle(vector<vector<int>> &board) {
        unordered_map<string, bool> visited;
        const auto target = "123450"s;
        auto initial = ""s;
        for (const auto &row : board)
            for (const auto &cell : row) initial += to_string(cell);
        auto ans = 0;
        if (initial == target) return ans;
        queue<string> bfs;
        visited[initial] = true;
        bfs.push(std::move(initial));
        while (!bfs.empty()) {
            ans++;
            for (auto i = bfs.size(); i > 0; i--) {
                auto current = std::move(bfs.front());
                bfs.pop();
                const auto zero = current.find('0');
                const auto x = zero / 3, y = zero % 3;
                for (auto at = 0uz; at < 4; at++) {
                    const auto new_x = x + direc[at], new_y = y + direc[at + 1];
                    if (new_x >= 2 or new_y >= 3) continue;
                    auto next = current;
                    swap(next[zero], next[new_x * 3 + new_y]);
                    if (visited[next]) continue;
                    if (next == target) return ans;
                    visited[next] = true;
                    bfs.push(std::move(next));
                }
            }
        }
        return -1;
    }
};