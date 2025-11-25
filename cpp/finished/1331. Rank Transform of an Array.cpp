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
    vector<int> arrayRankTransform(vector<int> &arr) {
        const auto n = arr.size();
        multimap<int, size_t> pos;
        vector<int> ans(n);
        for (size_t i = 0; i < n; i++) pos.emplace(arr[i], i);
        int rank = 1;
        ans[pos.begin()->second] = rank;
        for (auto itr = next(pos.begin()); itr != pos.end(); itr++) {
            if (itr->first != prev(itr)->first) rank++;
            ans[itr->second] = rank;
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int> &arr) {
//         ios_base::sync_with_stdio(0);
//         cin.tie(0);
//         cout.tie(0);
//         if (arr.size() == 0) return arr;
//         unordered_map<int, int> ranks;
//         vector<int> sorted(arr.begin(), arr.end());
//         sort(sorted.begin(), sorted.end());
//         int pre = sorted[0];
//         ranks[pre] = 1;
//         int R = 2;
//         for (int i = 1; i < sorted.size(); i++) {
//             if (sorted[i] == pre) continue;
//             ranks[sorted[i]] = R++;
//             pre = sorted[i];
//         }
//         for (int i = 0; i < arr.size(); i++)
//             sorted[i] = ranks[arr[i]];
//         return sorted;
//     }
// };