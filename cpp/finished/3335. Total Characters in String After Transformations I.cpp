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

constexpr long long MOD = 1e9 + 7;

class Matrix {
public:
    size_t row, col;
    vector<vector<long long>> elements;

    Matrix(size_t row, size_t col) : row(row), col(col) {
        elements.resize(row, vector<long long>(col, 0));
    };

    Matrix &operator*=(const Matrix &other) {
        Matrix result(row, other.col);
        for (size_t i = 0; i < result.row; i++) {
            for (size_t j = 0; j < result.col; j++) {
                for (size_t k = 0; k < col; k++) {
                    result.elements[i][j] += elements[i][k] * other.elements[k][j] % MOD;
                    result.elements[i][j] %= MOD;
                }
            }
        }
        return (*this = result);
    }

    static auto element_sum(const Matrix &mat) -> long long {
        auto sum = 0LL;
        for (const auto &row : mat.elements)
            for (const auto &ele : row) sum = (sum + ele) % MOD;
        return sum;
    }
    static auto identity(size_t size) -> Matrix {
        Matrix i(size, size);
        for (size_t j = 0; j < size; j++) i.elements[j][j] = 1;
        return i;
    }
};

Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix result(A);
    return result *= B;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        Matrix str(26, 1);
        Matrix transform(26, 26);
        for (size_t i = 1; i < 26; i++) transform.elements[i][i - 1] = 1;
        transform.elements[0][25] = transform.elements[1][25] = 1;
        for (const auto &c : s) str.elements[static_cast<size_t>(c - 'a')].front()++;
        Matrix result = Matrix::identity(26);
        while (t) {
            if (t & 1) result *= transform;
            transform *= transform;
            t >>= 1;
        }
        result *= str;
        return static_cast<int>(Matrix::element_sum(result));
    }
};