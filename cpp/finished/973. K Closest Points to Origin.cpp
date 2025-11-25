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
private:
    struct Point {
        int x;
        int y;
        double distance;
        Point(int X, int Y, double D) : x(X), y(Y), distance(D){};
    };

    struct cmp {
        bool operator()(const Point &a, const Point &b) {
            return a.distance < b.distance;
        }
    };

    double getDistance(int x, int y) {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        priority_queue<Point, vector<Point>, cmp> kept;
        double select = DBL_MAX;
        for (const auto &p : points) {
            double distance = getDistance(p[0], p[1]);
            if (distance > select && kept.size() == k) continue;
            kept.push(Point(p[0], p[1], distance));
            while (kept.size() > k)
                kept.pop();
            select = kept.top().distance;
        }
        vector<vector<int>> res;
        while (!kept.empty()) {
            res.push_back({kept.top().x, kept.top().y});
            kept.pop();
        }
        return res;
    }
};