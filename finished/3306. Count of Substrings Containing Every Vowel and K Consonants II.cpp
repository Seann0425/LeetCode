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

#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>
#ifndef DEBUG
#define DEBUG
template <typename T>
void debug(const vector<T> &v) {
    if (v.empty()) {
        cout << "[]"s << endl;
        return;
    }
    cout << '[' << v.front();
    for (const auto &x : v | views::drop(1)) cout << ',' << x;
    cout << "]" << endl;
}
void debug(const string &s) { cout << '"' << s << '"' << endl; }
#endif

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
    bool is_vowel(const char &c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
    size_t vowel_index(const char &c) {
        return c == 'a' ? 0uz : c == 'e' ? 1uz : c == 'i' ? 2uz : c == 'o' ? 3uz : 4uz;
    }
    bool all_vowels(const array<int, 5> &vowels) {
        return all_of(vowels.begin(), vowels.end(), [](const int &x) { return x; });
    }
    long long atleast_k(const string &word, int k) {
        auto ans = 0ll;
        auto consonants = 0;
        array<int, 5> vowels{};
        const auto n = word.size();
        auto l = 0uz, r = 0uz;
        while (r < n) {
            if (is_vowel(word[r])) ++vowels[vowel_index(word[r])];
            else ++consonants;
            while (consonants >= k and all_vowels(vowels)) {
                ans += n - r;
                if (!is_vowel(word[l])) --consonants;
                else --vowels[vowel_index(word[l])];
                ++l;
            }
            ++r;
        }
        return ans;
    }
public:
    long long countOfSubstrings(string word, int k) {
        return atleast_k(word, k) - atleast_k(word, k + 1);
    }
};