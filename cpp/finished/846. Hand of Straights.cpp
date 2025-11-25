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

class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        if (hand.size() % groupSize) return false;

        const auto N = hand.size();
        const int G = N / groupSize;
        sort(hand.begin(), hand.end());
        unordered_map<int, vector<int>> groups;
        int group_count = 0;
        for (size_t i = 0; i < N; i++) {
            bool bruh = false;
            for (auto &[begin, v] : groups) {
                for (auto &size : v) {
                    if (size < groupSize && begin + size == hand[i]) {
                        size++;
                        bruh = true;
                        break;
                    }
                }
                if (bruh) break;
            }
            if (bruh) continue;
            group_count++;
            if (group_count > G) return false;
            if (groups.count(hand[i])) groups[hand[i]].push_back(1);
            else groups.insert({hand[i], {1}});
        }
        return true;
    }
};