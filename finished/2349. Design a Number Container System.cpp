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

class NumberContainers {
    unordered_map<int, int> index_to_number;
    unordered_map<int, set<int>> number_to_index;
public:
    NumberContainers() {
        index_to_number.clear();
        number_to_index.clear();
    }

    void change(int index, int number) {
        if (index_to_number.contains(index)) {
            number_to_index[index_to_number[index]].erase(index);
            if (number_to_index[index_to_number[index]].empty())
                number_to_index.erase(index_to_number[index]);
        }
        index_to_number[index] = number;
        number_to_index[number].insert(index);
    }

    int find(int number) {
        if (number_to_index.contains(number)) return *number_to_index[number].begin();
        return -1;
    }
};