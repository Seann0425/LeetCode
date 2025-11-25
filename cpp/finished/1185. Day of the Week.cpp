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
    bool isLeap(int n) {
        if (!(n % 400)) return true;
        if (!(n % 100)) return false;
        if (!(n % 4)) return true;
        return false;
    }
public:
    string dayOfTheWeek(int day, int month, int year) {
        // 1971/01/01 is Friday
        vector<string> Youbi({"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"});
        int DAYS = 365 * (year - 1971) + (year - 1971 > 2) + ((year - 1971 - 2 > 0) ? ((year - 1971 - 2) / 4) : 0);
        vector<int> GeTsu({0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334});
        if (isLeap(year))
            for (int i = 2; i < 12; i++)
                GeTsu[i]++;
        DAYS += GeTsu[month - 1];
        DAYS += day;
        return Youbi[(DAYS - 1) % 7];
    }
};