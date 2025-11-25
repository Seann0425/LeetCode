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

struct pair_hash {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);

        return h1 ^ h2;
    }
};

typedef pair<int, int> Coordinate;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<Coordinate, pair_hash> obstacles_set;
        for (const auto &obstacle : obstacles) obstacles_set.emplace(obstacle.front(), obstacle.back());
        int x = 0, y = 0, ans = 0;
        size_t i = 0, j = 1;
        array<int, 4> direction{0, 1, 0, -1};
        for (const auto &command : commands) {
            // turn left
            if (command == -2) {
                i = min(i - 1, 3ULL);
                j = min(j - 1, 3ULL);
            }
            // turn right
            else if (command == -1) {
                i = (i + 1) % 4;
                j = (j + 1) % 4;
            }
            // walk
            else {
                for (int step = 0; step < command; step++) {
                    x += direction[i];
                    y += direction[j];
                    if (obstacles_set.count({x, y})) {
                        x -= direction[i];
                        y -= direction[j];
                        break;
                    }
                }
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};