#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        istringstream iss1(sentence1), iss2(sentence2);
        vector<string> s1, s2;
        string word;

        while (iss1 >> word) s1.push_back(std::move(word));
        while (iss2 >> word) s2.push_back(std::move(word));
        if (s1.size() < s2.size()) swap(s1, s2);

        const auto n1 = s1.size(), n2 = s2.size();
        auto l = 0uz, r = n2 - 1;
        while (l < n2 && s1[l] == s2[l]) l++;
        if (l == n2) return true;
        while (r < n2 && r >= l && s1[r + n1 - n2] == s2[r]) r--;
        return r >= n2 or r < l;
    }
};