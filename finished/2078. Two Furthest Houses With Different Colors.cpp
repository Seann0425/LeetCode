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
    int maxDistance(vector<int> &colors) {
        int first = 0, second;

        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] != colors[first]) {
                second = i;
                break;
            }
        }

        int firstEnd, secondEnd;
        bool F = true, S = true;
        for (int i = colors.size() - 1; i >= 0 && (F || S); i--) {
            if (F && colors[i] != colors[first]) firstEnd = i, F = false;
            if (S && colors[i] != colors[second]) secondEnd = i, S = false;
        }

        return max((firstEnd - first), (secondEnd - second));
    }
};