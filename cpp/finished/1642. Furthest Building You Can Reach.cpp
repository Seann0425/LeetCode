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
    typedef pair<int, int> pInt;
    typedef priority_queue<int, vector<int>, greater<int>> KPQueue;

    void insertCost(KPQueue &ladderCost, int &height, int &brickCost, const int &ladders) {
        if (ladderCost.size() < ladders) {
            ladderCost.push(height);
            return;
        }
        if (ladders == 0 || height < ladderCost.top()) {
            brickCost += height;
        } else {
            ladderCost.push(height);
            brickCost += ladderCost.top();
            ladderCost.pop();
        }
        return;
    }
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        // record the differences of height
        vector<pInt> barriers; // height, furthest reachable
        int furthest = 0;      // answer
        bool flag = true;
        for (int i = 1; i < heights.size(); i++) {
            if (flag && heights[i] <= heights[i - 1]) furthest = i;
            if (heights[i] > heights[i - 1]) {
                flag = false;
                if (!barriers.empty()) barriers.back().second = i - 1;
                barriers.push_back(make_pair(heights[i] - heights[i - 1], -1));
            }
        }
        if (!barriers.empty()) {
            barriers.back().second = heights.size() - 1;
        } else return heights.size() - 1;

        int brickCost = 0;
        KPQueue ladderCost;
        for (int i = 0; i < barriers.size(); i++) {
            insertCost(ladderCost, barriers[i].first, brickCost, ladders);
            if (brickCost > bricks) break;
            furthest = barriers[i].second;
            if (brickCost == bricks) break;
        }

        return furthest;
    }
};