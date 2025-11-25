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
    int daysBetweenDates(string date1, string date2) {
        return abs(date_to_int(date2) - date_to_int(date1));
    }
protected:
    int date_to_int(string s_date) {
        int Y = stoi(s_date.substr(0, 4));
        int M = stoi(s_date.substr(5, 2));
        int D = stoi(s_date.substr(8, 2));

        int date = 0;
        for (int y = 1971; y < Y; ++y)
            date += is_leap_year(y) ? 366 : 365;
        for (int m = 1; m < M; ++m)
            date += days_in_month(m, Y);
        return date + D;
    }

    bool is_leap_year(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    int days_in_month(int m, int year) {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
        if (m == 2) return is_leap_year(year) ? 29 : 28;
        return 30;
    }
};