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
    vector<int> factorization(int n) {
        // could be optimized
        vector<int> factors;
        for (int d = 2; d * d <= n; d++) {
            if (n % d == 0) factors.push_back(d);
            while (n % d == 0)
                n /= d;
        }
        if (n > 1) factors.push_back(n);
        return factors;
    }

    int findLeader(int follower, unordered_map<int, int> &belongs) {
        if (belongs[follower] == follower) return follower;
        else {
            belongs[follower] = findLeader(belongs[follower], belongs);
            return belongs[follower];
        }
    }

    void merge(int left, int right, unordered_map<int, int> &belongs) {
        // left is smaller than right
        int leftLeader = findLeader(left, belongs);
        int rightLeader = findLeader(right, belongs);
        if (leftLeader != rightLeader) belongs[rightLeader] = leftLeader;
        return;
    }
public:
    bool canTraverseAllPairs(vector<int> &nums) {
        // union find DS
        unordered_map<int, int> belongs;

        for (const auto &i : nums) {
            if (i == 1) {
                belongs[1] = 1;
                continue;
            }
            // the part of merge could be optimized
            vector<int> divisors = factorization(i);

            for (const auto &d : divisors) {
                if (!belongs.count(d)) belongs[d] = divisors[0];
                else merge(divisors[0], d, belongs);
            }
        }

        int setCnt = 0;
        for (const auto &itr : belongs) {
            if (itr.first == itr.second) {
                // leader of one set
                setCnt++;
            }
        }

        if (belongs.count(1) && nums.size() > 1) return false;
        return setCnt == 1;
    }
};