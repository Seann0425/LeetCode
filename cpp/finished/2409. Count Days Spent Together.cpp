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
    vector<int> months = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int toValue(string &date) {
        return months[stoi(date.substr(0, 2)) - 1] + stoi(date.substr(3, 2));
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<vector<int>> inRome;
        inRome.push_back({toValue(arriveAlice), toValue(leaveAlice)});
        inRome.push_back({toValue(arriveBob), toValue(leaveBob)});
        sort(inRome.begin(), inRome.end());
        if (inRome[1][0] <= inRome[0][1]) return min(inRome[0][1], inRome[1][1]) - max(inRome[0][0], inRome[1][0]) + 1;
        else return 0;
    }
};