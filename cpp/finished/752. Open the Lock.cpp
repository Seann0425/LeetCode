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
    int openLock(vector<string> &deadends, string target) {
        const array<uint16_t, 4> wheels{1, 10, 100, 1000};
        const auto target_n = static_cast<uint16_t>(stoul(target));
        bitset<10000> visited;
        queue<uint16_t> q, q_next;
        for (const auto &stuck : deadends) {
            visited.set(stoul(stuck));
        }
        if (visited.test(0)) return -1;
        visited.set(0);
        q.push(0);
        uint16_t digit, tmp;
        int dist = 0;
        while (!q.empty()) {
            auto lock = q.front();
            q.pop();
            if (lock == target_n) return dist;
            for (const auto &wheel : wheels) {
                digit = lock % (wheel * 10) / wheel;
                tmp = (digit == 9) ? (lock - 9 * wheel) : (lock + wheel);
                if (!visited.test(tmp)) {
                    visited.set(tmp);
                    q_next.push(tmp);
                }
                tmp = (digit == 0) ? (lock + 9 * wheel) : (lock - wheel);
                if (!visited.test(tmp)) {
                    visited.set(tmp);
                    q_next.push(tmp);
                }
            }
            if (q.empty()) {
                swap(q, q_next);
                dist++;
            }
        }
        return -1;
    }
};