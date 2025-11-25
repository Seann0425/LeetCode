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
    vector<string> removeSubfolders(vector<string> &folder) {
        const auto n = folder.size();
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.reserve(n);

        string prev = folder.front() + "/"s;
        ans.push_back(std::move(folder.front()));
        for (size_t i = 1; i < n; i++) {
            string tmp = folder[i] + "/"s;
            if (tmp.starts_with(prev)) continue;
            else {
                ans.push_back(std::move(folder[i]));
                prev = tmp;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<string> removeSubfolders(vector<string> &folder) {
//         const int n = static_cast<int>(folder.size());
//         sort(folder.begin(), folder.end());

//         string prev = folder[0] + "/"s;
//         vector<string> ans;
//         ans.push_back(folder[0]);
//         for (int i = 1; i < n; i++) {
//             string tmp = folder[i] + "/";
//             if (tmp.starts_with(prev)) continue;
//             else {
//                 ans.push_back(folder[i]);
//                 prev = tmp;
//             }
//         }
//         return ans;
//     }
// };