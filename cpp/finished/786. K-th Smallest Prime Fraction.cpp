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

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto __ = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

typedef pair<int, int> PrimeFraction;
class Solution {
    struct comparePrimeFraction {
        bool operator()(PrimeFraction a, PrimeFraction b) {
            return a.first * b.second < b.first * a.second;
        }
    };
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        priority_queue<PrimeFraction, vector<PrimeFraction>, comparePrimeFraction> heap;
        const auto N = arr.size();
        for (size_t i = 0; i < N; i++) {
            for (size_t j = i + 1; j < N; j++) {
                heap.emplace(arr[i], arr[j]);
                if (heap.size() > k) heap.pop();
            }
        }
        return {heap.top().first, heap.top().second};
    }
};