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

class dsu_t {
    vector<size_t> parent;
    vector<size_t> size;
public:
    explicit dsu_t(size_t n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }
    size_t find(size_t n) {
        return parent[n] == n ? n : parent[n] = find(parent[n]);
    } // path compression

    bool unite(size_t a, size_t b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; // already connected
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    size_t size_of(size_t n) { return size[find(n)]; }
    size_t max_union() { return *max_element(size.begin(), size.end()); }
};

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) return 0;
        const auto n = nums.size();
        unordered_map<int, size_t> mp;
        dsu_t dsu(n);
        for (auto i = 0uz; i < n; i++) {
            if (mp.contains(nums[i])) continue;
            mp[nums[i]] = i;
            if (mp.contains(nums[i] - 1)) dsu.unite(i, mp[nums[i] - 1]);
            if (mp.contains(nums[i] + 1)) dsu.unite(i, mp[nums[i] + 1]);
        }
        return dsu.max_union();
    }
};