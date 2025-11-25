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

#include <ranges>
class Solution {
    bool valid_mutation(const string_view &a, const string_view &b) {
        auto diff = 0;
        for (const auto &[x, y] : views::zip(a, b))
            if (diff += (x != y); diff > 1) return false;
        return diff == 1;
    }
public:
    int minMutation(string start_gene, string end_gene, vector<string> &bank) {
        bank.push_back(start_gene);
        const auto n = bank.size();
        string_view end(end_gene);
        queue<string_view> bfs{};
        bitset<11> visited{};
        visited.set(n - 1);
        bfs.emplace(start_gene);
        auto level = 0;
        while (!bfs.empty()) {
            auto size = bfs.size();
            while (size--) {
                auto gene = bfs.front();
                bfs.pop();
                if (gene == end) return level;
                for (auto i = 0uz; i < n; i++) {
                    if (visited[i]) continue;
                    if (valid_mutation(gene, bank[i])) {
                        visited.set(i);
                        bfs.emplace(bank[i]);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};