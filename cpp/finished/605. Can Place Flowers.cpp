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

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        auto count = 0;
        const auto n_size = flowerbed.size();
        for (size_t i = 0; i < n_size; i++) {
            if (!flowerbed[i]) {
                if ((!i or !flowerbed[i - 1]) && (i == n_size - 1 or !flowerbed[i + 1])) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        return count >= n;
    }
};

// class Solution {
// public:
//     bool canPlaceFlowers(vector<int> &flowerbed, int n) {
//         ios_base::sync_with_stdio(0);
//         cin.tie(0);
//         int vacancy = 0;
//         int s = flowerbed.size();
//         bool front = 0;
//         int size = 0;
//         for (int i = 0; i < s; i++) {
//             if (!flowerbed[i]) size++;
//             else {
//                 if (front) vacancy += (size - 1) / 2;
//                 else vacancy += size / 2;
//                 size = 0;
//                 front = 1;
//             }
//         }
//         if (size) vacancy += (front) ? (size / 2) : (size / 2 + size % 2);
//         return vacancy >= n;
//     }
// };