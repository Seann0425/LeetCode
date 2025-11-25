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
    string oddString(vector<string> &v1) {
        int n = v1.size(), m = v1[0].size();
        string ans = "";
        map<vector<int>, vector<string>> m1;
        for (auto &it : v1) {
            vector<int> a;
            for (int i = 1; i < m; i++)
                a.push_back(it[i] - it[i - 1]);
            m1[a].push_back(it);
        }
        for (auto &it : m1) {
            if (it.second.size() == 1) {
                ans = it.second[0];
                break;
            }
        }
        return ans;
    }
};