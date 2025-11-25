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
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) { // `n` is useless
        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });

        vector<vector<pair<int, int>>> time_meetings_v;
        int tmp = -1, now = -1, time;
        for (const auto &meeting : meetings) {
            if ((time = meeting[2]) != now) {
                tmp++, now = time;
                time_meetings_v.emplace_back(vector<pair<int, int>>());
            }
            time_meetings_v[tmp].emplace_back(meeting[0], meeting[1]);
        }

        vector<int> ans{0, firstPerson};
        bitset<100005> know;
        know[0] = know[firstPerson] = true;
        bool p1_in, p2_in;
        queue<int> q;
        for (const auto &meetings_v : time_meetings_v) {
            unordered_map<int, vector<int>> graph;
            unordered_set<int> starts;
            for (const auto &[p1, p2] : meetings_v) { // build graph & start
                p1_in = know[p1], p2_in = know[p2];
                if (p1_in && p2_in) continue;
                if (p1_in) {
                    know[p2] = true;
                    ans.push_back(p2);
                    starts.insert(p2);
                    continue;
                }
                if (p2_in) {
                    know[p1] = true;
                    ans.push_back(p1);
                    starts.insert(p1);
                    continue;
                }
                graph[p1].push_back(p2);
                graph[p2].push_back(p1);
            }

            for (const auto &start : starts) { // BFS all start points
                q.push(start);
                while (!q.empty()) {
                    tmp = q.front();
                    q.pop();
                    for (const auto &node : graph[tmp]) {
                        if (know[node]) continue;
                        know[node] = true;
                        ans.push_back(node);
                        q.push(node);
                    }
                }
            }
        }
        return ans;
    }
};