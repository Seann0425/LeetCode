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

class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        int head = 0, tail = arr.size() - 1;
        if (arr[tail] - (tail + 1) < k) return arr[tail] + k - (arr[tail] - (tail + 1));
        if (arr[head] - (head + 1) >= k) return k;
        while (tail - head > 1) {
            int mid = (head + tail) / 2;
            if (arr[mid] - (mid + 1) >= k) tail = mid;
            else if (arr[mid] - (mid + 1) < k) head = mid;
        }
        return arr[head] + k - (arr[head] - (head + 1));
    }
};