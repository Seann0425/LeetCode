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
    vector<int> mostVisited(int n, vector<int> &rounds) {
        vector<int> cnt(n, 0);
        cnt[rounds[0] - 1] = 1;
        for (int i = 1; i < rounds.size(); i++) {
            if (rounds[i] >= rounds[i - 1])
                for (int j = rounds[i]; j > rounds[i - 1]; j--)
                    cnt[j - 1]++;
            else {
                for (int j = rounds[i - 1]; j % n != rounds[i]; j++) {
                    cnt[j % n]++;
                }
            }
        }
        int maximum = *(max_element(cnt.begin(), cnt.end()));
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (cnt[i] == maximum) ans.push_back(i + 1);
        return ans;
    }
};