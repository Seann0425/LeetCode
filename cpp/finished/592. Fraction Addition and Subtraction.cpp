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
    template <typename T>
    T lcm(T a, T b) {
        return a * b / gcd(a, b);
    }
    long long lcm_of_array(const vector<int>& nums) {
        const auto n = nums.size();
        auto ans = static_cast<long long>(nums.front());
        for (size_t i = 1; i < n; i++) {
            ans = lcm<long long>(ans, nums[i]);
        }
        return ans;
    }
    void reduce(long long &numer, long long &deno) {
        while (!(numer % 2 || deno % 2)) {
            numer /= 2;
            deno /= 2;
        }

        for (long long i = 3; i <= min(abs(numer), abs(deno)); i += 2) {
            while (!(numer % i || deno % i)) {
                numer /= i;
                deno /= i;
            }
        }
    }
public:
    string fractionAddition(string expression) {
        vector<int> numerators, denominators;
        vector<bool> is_negative;
        const auto n = expression.size();
        
        for (size_t i = 0; i < n; i++) {
            is_negative.push_back(expression[i++] == '-');
            if (isdigit(expression[i - 1])) i--;

            int tmp = 0;
            while(isdigit(expression[i])) tmp = tmp * 10 + (expression[i++] - '0');
            numerators.push_back(tmp);
            i++;
            tmp = 0;

            while(i < n && isdigit(expression[i])) tmp = tmp * 10 + (expression[i++] - '0');
            denominators.push_back(tmp);
            i--;
        }

        long long res_denominators = lcm_of_array(denominators);
        long long res_numerator = 0;
        const auto n_nums = numerators.size();
        
        for (size_t i = 0; i < n_nums; i++) {
            res_numerator += (is_negative[i] ? -1 : 1) * (numerators[i] * (res_denominators / denominators[i]));
        }

        reduce(res_numerator, res_denominators);

        return to_string(res_numerator) + '/' + to_string(res_denominators);
    }
};