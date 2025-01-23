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

// inspired by Huffman Code
class Solution {
public:
    int mctFromLeafValues(vector<int> &arr) {
        list<int> leafs(arr.begin(), arr.end());
        auto ans = 0;
        while (leafs.size() > 1) {
            auto min_it = leafs.begin();
            auto min_val = *min_it * *next(min_it);
            for (auto it = next(min_it); it != prev(leafs.end()); it++) {
                const auto val = *it * *next(it);
                if (val < min_val) {
                    min_val = val;
                    min_it = it;
                }
            }
            ans += min_val;
            leafs.erase(*min_it > *next(min_it) ? next(min_it) : min_it);
        }
        return ans;
    }
};