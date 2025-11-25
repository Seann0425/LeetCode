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
    string removeDuplicateLetters(string s) {
        stack<char> s_temp;
        bitset<26> exist;
        array<int, 26> last_seen{};
        for (int i = 0; i < static_cast<int>(s.size()); i++)
            last_seen[s[i] - 'a'] = i;
        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            if (exist.test(s[i] - 'a')) continue;
            while (!s_temp.empty() && s_temp.top() > s[i] && last_seen[s_temp.top() - 'a'] > i) {
                exist.reset(s_temp.top() - 'a');
                s_temp.pop();
            }
            exist.set(s[i] - 'a');
            s_temp.push(s[i]);
        }
        string ans{};
        while (!s_temp.empty()) {
            ans = s_temp.top() + ans;
            s_temp.pop();
        }
        return ans;
    }
};