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
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        map<int, int> cntr;
        size_t idx = 0;
        for (const auto &i : arr1)
            cntr[i]++;
        for (const auto &i : arr2) {
            while (cntr[i]--)
                arr1[idx++] = i;
        }
        for (auto &ele : cntr) {
            while (ele.second--)
                arr1[idx++] = ele.first;
        }
        return arr1;
    }
};

// class Solution {
// public:
//     vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
//         ios_base::sync_with_stdio(0);
//         cin.tie(0);
//         cout.tie(0);
//         map<int, int> countingSort;
//         vector<int> result;
//         for (int n : arr1)
//             countingSort[n]++;
//         for (int ele : arr2) {
//             while (countingSort[ele]) {
//                 countingSort[ele]--;
//                 result.push_back(ele);
//             }
//         }
//         for (auto itr = countingSort.begin(); itr != countingSort.end(); itr++) {
//             while (itr->second) {
//                 itr->second--;
//                 result.push_back(itr->first);
//             }
//         }
//         return result;
//     }
// };