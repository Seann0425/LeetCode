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
    int compareVersion(string version1, string version2) {
        size_t i_start = 0, i_end = 0;
        size_t j_start = 0, j_end = 0;
        const auto N = version1.size(), M = version2.size();
        while (i_start < N || j_start < M) {
            int i_revision, j_revision;
            if ((i_end = version1.find('.', i_start)) != string::npos) i_revision = stoi(version1.substr(i_start, i_end - i_start));
            else if (i_start < N) i_revision = stoi(version1.substr(i_start, N - i_start));
            else i_revision = 0;
            if ((j_end = version2.find('.', j_start)) != string::npos) j_revision = stoi(version2.substr(j_start, j_end - j_start));
            else if (j_start < M) j_revision = stoi(version2.substr(j_start, M - j_start));
            else j_revision = 0;
            if (i_revision != j_revision) return (i_revision > j_revision) ? 1 : -1;
            if (i_start != N) i_start = (i_end == string::npos) ? N : i_end + 1;
            if (j_start != M) j_start = (j_end == string::npos) ? M : j_end + 1;
        }
        return 0;
    }
};