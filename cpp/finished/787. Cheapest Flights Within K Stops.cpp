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
    typedef pair<int, int> iPair;
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<list<iPair>> adjGraph(n);
        for (const auto &f : flights)
            adjGraph[f[0]].push_back(make_pair(f[1], f[2]));

        vector<int> cost(n, 0), tmp(n, 0);
        queue<int> curLevel({src}); // 我還真沒有用過queue的constructor
        int startingNode, prefixCost, nextCost, nextNode, newCost, ans = -1;
        decltype(adjGraph[0].begin()) begin; // 這真的好帥，以後我連int都這樣宣告
        k++;

        while (k--) {
            while (!curLevel.empty()) {
                startingNode = curLevel.front(), prefixCost = cost[startingNode];
                for (begin = adjGraph[startingNode].begin(); begin != adjGraph[startingNode].end(); begin++) {
                    tie(nextNode, newCost) = *begin, nextCost = cost[nextNode], newCost += prefixCost;
                    if (nextNode != src && (nextCost == 0 || newCost < nextCost) && (tmp[nextNode] == 0 || newCost < tmp[nextNode]))
                        tmp[nextNode] = newCost;
                }
                curLevel.pop();
            }

            for (int i = 0; i < n; i++) {
                if (i == dst && tmp[dst]) ans = tmp[dst];     // dest has been processed
                else if (cost[i] != tmp[i]) curLevel.push(i); // minimum cost's been updated
            }
            copy(tmp.begin(), tmp.end(), cost.begin()); // 這也沒用過
        }

        return ans;
    }
};