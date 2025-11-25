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
    typedef pair<long long, int> LIPair;
public:
    vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq) {
        unordered_map<int, long long> cur_freq;
        priority_queue<LIPair> pq;
        vector<long long> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            cur_freq[nums[i]] += static_cast<long long>(freq[i]);
            pq.emplace(cur_freq[nums[i]], nums[i]);
            while (pq.top().first != cur_freq[pq.top().second])
                pq.pop();
            ans[i] = pq.top().first;
        }
        return ans;
    }
};