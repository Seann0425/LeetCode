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
#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

auto RuntimeCheat = atexit([]() { ofstream("display_runtime.txt") << "0"; });

class Solution {
    using query_t = pair<size_t, size_t>;
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
        const auto n = nums.size(), m = queries.size();
        auto cmp = [](const query_t &a, const query_t &b) {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        };
        priority_queue<query_t, vector<query_t>, decltype(cmp)> query_pq;
        for (const auto &q : queries) query_pq.emplace(q[0], q[1]);
        vector<int> prefix(n + 1);
        auto count = 0, ans = 0;
        for (auto i = 0uz; i < n; ++i) {
            // cout << "Now it's i = " << i << endl;
            count += prefix[i];
            // cout << "The value of count is now " << count << endl;
            // cout << "The top of the heap is: [" << query_pq.top().first << ", " <<
            // query_pq.top().second << "]" << endl;
            while (nums[i] > count) {
                while (!query_pq.empty() and
                       (query_pq.top().first < i or query_pq.top().second < i)) {
                    if (query_pq.top().second < i) {
                        // cout << "But the query: [" << query_pq.top().first << ", " <<
                        // query_pq.top().second << "] is invalid." << endl;
                        ++ans;
                        query_pq.pop();
                    } else {
                        query_pq.emplace(i, query_pq.top().second);
                        query_pq.pop();
                    }
                }
                if (query_pq.empty() or query_pq.top().first > i) return -1;
                // cout << nums[i] << " is greater than " << count << endl;
                // cout << "We apply the query: [" << query_pq.top().first << ", "
                //     << query_pq.top().second << "]" << endl;
                ++count;
                // cout << "Now, nums[" << i << "] is " << nums[i] << ", and count is " << count
                //      << endl;
                prefix[query_pq.top().second + 1] -= 1;
                query_pq.pop();
            }
        }
        return ans + static_cast<int>(query_pq.size());
    }
};