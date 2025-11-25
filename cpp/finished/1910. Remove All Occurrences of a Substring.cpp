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

#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>
#ifndef DEBUG
#define DEBUG
template <typename T>
void debug(const vector<T> &v) {
    if (v.empty()) {
        cout << "[]"s << endl;
        return;
    }
    cout << '[' << v.front();
    for (const auto &x : v | views::drop(1)) cout << ',' << x;
    cout << "]" << endl;
}
void debug(const string &s) { cout << s << endl; }
#endif

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// mindless standard library solution
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) s.erase(s.find(part), part.size());
        return s;
    }
};

// kmp practice
class Solution {
    vector<int> get_next(const string &p) {
        const auto n = p.size();
        vector<int> next(n, 0);
        for (auto suf = 1, pre = 0; suf < n; suf++) {
            if (p[suf] == p[pre]) next[suf] = ++pre;
            else if (!pre) next[suf] = 0;
            else pre = next[pre - 1], suf--;
        }
        return next;
    }
public:
    string removeOccurrences(string s, string pattern) {
        vector<int> next; // next character to match in pattern
        vector<int> lps = get_next(pattern);
        string ans{};
        const auto n = s.size(), m = pattern.size();
        auto i = 0uz, j = 0uz;
        while (i < n) {
            if (s[i] == pattern[j]) {
                if (++j == m) {
                    ans.resize(ans.size() - m + 1);
                    next.resize(next.size() - m + 1);
                    if (next.empty()) j = 0;
                    else j = next.back();
                    i++;
                } else {
                    ans.push_back(s[i++]);
                    next.push_back(j);
                }
            } else if (j) {
                j = lps[j - 1];
                continue;
            } else ans.push_back(s[i++]), next.push_back(0), j = 0uz;
        }
        return ans;
    }
};