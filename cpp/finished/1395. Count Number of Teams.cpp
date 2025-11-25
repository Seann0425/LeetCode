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

// use indexed array
// inspired from Pashka
template <typename T>
class SegmentTree {
public:
    size_t size;
    vector<T> tree;
    const T DEFAULT = T{};

    T merge(T a, T b) { return a + b; }

    void init(size_t n) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size - 1, DEFAULT);
    }

    // void build(vector<int> &a,ll x,ll lx,ll rx) {
    //     //base case
    //     if(rx-lx == 1) {
    //         if(lx < int(a.size())) {
    //             values[x] = single(a[lx]);
    //         }
    //         return;
    //     }

    //     ll m = (lx+rx)/2;
    //     build(a,2*x +1,lx,m);
    //     build(a,2*x +2,m,rx);
    //     values[x] = merge(values[2*x +1],values[2*x +2]);
    // }

    // void build(vector<int> &a) {
    //     build(a,0,0,size);
    // }

    void set(size_t idx, T val, size_t x, size_t lx, size_t rx) {
        if (rx - lx == 1) {
            tree[x] = val;
            return;
        }
        size_t m = (lx + rx) / 2;
        if (idx < m) set(idx, val, 2 * x + 1, lx, m);
        else set(idx, val, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(size_t idx, T val) { set(idx, val, 0, 0, size); }

    T calc(size_t l, size_t r, size_t x, size_t lx, size_t rx) {
        if (lx >= r or l >= rx) return DEFAULT;
        if (lx >= l and rx <= r) return tree[x];

        size_t m = (lx + rx) / 2;
        T s1 = calc(l, r, 2 * x + 1, lx, m);
        T s2 = calc(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }

    T query(size_t l, size_t r) { return calc(l, r + 1, 0, 0, size); }
};

class Solution {
public:
    int numTeams(vector<int> &rating) {
        const size_t max_size = 1e5;
        SegmentTree<int> st1, st2;
        st1.init(max_size);
        st2.init(max_size);

        auto n = rating.size();
        for (size_t i = 0; i < n; i++) st2.set(static_cast<size_t>(rating[i]), 1);

        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            auto left_small = st1.query(0, static_cast<size_t>(rating[i]) - 1);
            auto left_large = st1.query(static_cast<size_t>(rating[i]) + 1, max_size);
            auto right_small = st2.query(0, static_cast<size_t>(rating[i]) - 1) - left_small;
            auto right_large = st2.query(static_cast<size_t>(rating[i]) + 1, max_size) - left_large;
            st1.set(static_cast<size_t>(rating[i]), 1);
            ans += left_small * right_large + left_large * right_small;
        }
        return ans;
    }
};