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

constexpr size_t max_n = 1005;

constexpr auto is_primes = []() consteval {
    array<bool, max_n> is_prime;
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    const size_t smaller_max_n = max_n / 10;
    for (size_t i = 2; i <= smaller_max_n; i++) {
        if (is_prime[i]) {
            for (size_t j = i * i; j < max_n; j += i) is_prime[j] = false;
        }
    }
    return is_prime;
}();

class Solution {
    void prime_sub(int &num, int prev, const vector<int> &primes) {
        auto gap = num - prev;
        if (gap <= 0) return;
        auto sub = upper_bound(primes.rbegin(), primes.rend(), gap, greater<int>());
        if (sub == primes.rend()) return;
        num -= *sub;
    }
public:
    bool primeSubOperation(vector<int> &nums) {
        vector<int> primes;
        for (size_t i = 2; i < max_n; i++)
            if (is_primes[i]) primes.push_back(i);
        const auto n = nums.size();
        prime_sub(nums[0], 0, primes);
        for (size_t i = 1; i < n; i++) {
            prime_sub(nums[i], nums[i - 1], primes);
            if (nums[i] <= nums[i - 1]) return false;
        }
        return true;
    }
};