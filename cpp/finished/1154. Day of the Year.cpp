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
    int dayOfYear(string date) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string extract;
        // year
        int year;
        for (int i = 0; i < 4; i++)
            extract.push_back(date[i]);
        year = stoi(extract);
        extract.clear();
        // month
        int month;
        for (int i = 5; i < 7; i++)
            extract.push_back(date[i]);
        month = stoi(extract);
        extract.clear();
        // day
        int day;
        for (int i = 8; i < 10; i++)
            extract.push_back(date[i]);
        day = stoi(extract);
        // setup
        vector<int> calendar({0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334});
        bool leap_year = (((!(year % 4)) && (year % 100)) || (!(year % 400)));
        if (leap_year)
            for (int i = 2; i < 12; i++)
                calendar[i]++;
        return calendar[month - 1] + day;
    }
};