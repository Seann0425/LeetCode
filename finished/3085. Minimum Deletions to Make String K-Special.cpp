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
    int minimumDeletions(string word, int k) {
        array<int, 26> alphabet{};
        int deletion = 0, minimum = static_cast<int>(word.size());
        for (const auto &ch : word) alphabet[ch - 'a']++;
        sort(alphabet.begin(), alphabet.end());
        for (int i = 0; i < 26; i++) {
            int res = deletion, minFreq = alphabet[i];
            for (int j = 25; j > i; j--) {
                if (alphabet[j] - minFreq <= k) break;
                res += alphabet[j] - minFreq - k;
            }
            minimum = min(minimum, res);
            deletion += alphabet[i];
        }
        return minimum;
    }
};