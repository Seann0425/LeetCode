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
    int leastInterval(vector<char> &tasks, int n) {
        array<int, 26> alphabet{};
        for (const auto &task : tasks)
            alphabet[task - 'A']++;
        sort(alphabet.begin(), alphabet.end(), greater<int>());
        int chunk = alphabet[0] - 1;
        int idle = chunk * n;
        for (int i = 1; i < 26; i++)
            idle -= min(chunk, alphabet[i]);
        return idle < 0 ? static_cast<int>(tasks.size()) : static_cast<int>(tasks.size()) + idle;
    }
};