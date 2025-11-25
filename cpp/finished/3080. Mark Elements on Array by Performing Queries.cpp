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
    typedef pair<int, int> IntPair;
    struct myCmp {
        bool operator()(const IntPair &a, const IntPair &b) {
            if (a.second == b.second) return a.first > b.first;
            else return a.second > b.second;
        }
    };
public:
    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries) {
        priority_queue<IntPair, vector<IntPair>, myCmp> num_queue; // index, value
        long long sum = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            num_queue.emplace(i, nums[i]);
            sum += static_cast<long long>(nums[i]);
        }
        bitset<100005> marked;
        vector<long long> ans;
        for (const auto &query : queries) {
            if (!marked.test(query[0])) {
                marked.set(query[0]);
                sum -= static_cast<long long>(nums[query[0]]);
            }
            for (int i = 0; i < query[1]; i++) {
                while (!num_queue.empty() && marked.test(num_queue.top().first))
                    num_queue.pop();
                if (!num_queue.empty()) {
                    marked.set(num_queue.top().first);
                    sum -= static_cast<long long>(num_queue.top().second);
                    num_queue.pop();
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};