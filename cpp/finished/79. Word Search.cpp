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

/*the solution should start from below*/

class Solution {
    array<int, 5> mawari{0, 1, 0, -1, 0};
    typedef pair<int, int> IntPair;
    bool ans;
    void dfs(const vector<vector<char>> &board, vector<vector<bool>> &visited, stack<IntPair> &route, const string &word) {
        if (route.size() == word.size()) {
            ans = true;
            return;
        }
        int y = route.top().first, x = route.top().second;
        visited[y][x] = true;
        for (int at = 0; at <= 4; at++) {
            int y_new = y + mawari[at], x_new = x + mawari[at + 1];
            if (y_new < 0 || y_new >= board.size() || x_new < 0 || x_new >= board[0].size()) continue;
            if (board[y_new][x_new] != word[route.size()] || visited[y_new][x_new]) continue;
            route.emplace(y_new, x_new);
            dfs(board, visited, route, word);
            if (ans) return;
        }
        visited[y][x] = false;
        route.pop();
    }
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.size() * board[0].size() < word.size()) return false;
        ans = false;
        stack<IntPair> route;
        vector<vector<bool>> visited(board.size(), vector<bool>(board.front().size()));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != word.front()) continue;
                route.emplace(i, j);
                dfs(board, visited, route, word);
                if (ans) return ans;
            }
        }
        return ans;
    }
};