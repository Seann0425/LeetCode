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
void debug(const string &s) { cout << '"' << s << '"' << endl; }
#endif

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
    void add_nucleotides(bitset<20> &cur, char c) {
        cur <<= 2;
        switch (c) {
        case 'A':
            break;
        case 'C':
            cur |= 1;
            break;
        case 'G':
            cur |= 2;
            break;
        case 'T':
            cur |= 3;
            break;
        }
    }
    string to_dna_sequence(const bitset<20> &cur) {
        string ans(10, ' ');
        for (auto i = 0uz; i < 10uz; ++i) {
            switch (cur[i * 2] | (cur[i * 2 + 1] << 1)) {
            case 0:
                ans[9 - i] = 'A';
                break;
            case 1:
                ans[9 - i] = 'C';
                break;
            case 2:
                ans[9 - i] = 'G';
                break;
            case 3:
                ans[9 - i] = 'T';
                break;
            }
        }
        return ans;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        unordered_map<bitset<20>, int> seen;
        bitset<20> cur{};
        for (const auto &c : s | views::take(10)) add_nucleotides(cur, c);
        seen[cur] = 1;
        vector<string> ans{};
        for (const auto &c : s | views::drop(10)) {
            add_nucleotides(cur, c);
            if (++seen[cur] == 2) ans.push_back(to_dna_sequence(cur));
        }
        return ans;
    }
};