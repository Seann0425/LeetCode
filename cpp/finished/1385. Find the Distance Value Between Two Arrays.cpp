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
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(arr2.begin(), arr2.end());
        int below = arr2[0] - d - 1, above = arr2[arr2.size() - 1] + d + 1;
        vector<vector<int>> interval;
        for (int i = 1; i < arr2.size(); i++)
            if (arr2[i] - arr2[i - 1] >= 2 * (d + 1)) interval.push_back({arr2[i - 1], arr2[i]});
        int DV = 0;
        for (int i : arr1) {
            if (i <= below || i >= above) {
                DV++;
                continue;
            }
            for (int j = 0; j < interval.size(); j++) {
                if (i - interval[j][0] > d && interval[j][1] - i > d) {
                    DV++;
                    break;
                }
            }
        }
        return DV;
    }
};