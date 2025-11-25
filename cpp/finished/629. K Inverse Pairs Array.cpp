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
private:
    const int mod = 1000000000 + 7;
    vector<vector<int>> DP = vector<vector<int>>(1000, vector<int>(1001, 0));
    // int getAnswer(int n, int k){
    //     if(n==1) return DP[n-1][k];
    //     int cur = 0;
    //     for(int i=k;i>=(k-n+1);i--){
    //         if(i<0) break;
    //         cur += (DP[n-2][i] == 0)?getAnswer(n-1, i):DP[n-2][i];
    //         cur %= mod;
    //     }
    //     DP[n-1][k] = cur;
    //     return cur;
    // }
public:
    int kInversePairs(int n, int k) {
        DP[0][0] = 1;
        for (int i = 1; i < n; i++) {
            for (int tmpK = 0; tmpK <= k; tmpK++) {
                int cur = 0;
                for (int j = tmpK; j >= tmpK - i; j--) {
                    if (j < 0) break;
                    cur += DP[i - 1][j];
                    cur %= mod;
                }
                DP[i][tmpK] = cur;
                if (cur == 0) break;
            }
        }
        return DP[n - 1][k];
    }
};