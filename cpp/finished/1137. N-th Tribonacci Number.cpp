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

const size_t N = 1 + 37;

constexpr array<int, N> ans = []() consteval {
    array<int, N> tmp;
    tmp[0] = 0;
    tmp[1] = 1;
    tmp[2] = 1;
    for (size_t i = 3; i < N; i++) { tmp[i] = tmp[i - 1] + tmp[i - 2] + tmp[i - 3]; }
    return tmp;
}();

class Solution {
public:
    int tribonacci(int n) { return ans[n]; }
};

// class Matrix {
// public:
//     size_t row, col;
//     vector<vector<long long>> elements;

//     Matrix(size_t row, size_t col) : row(row), col(col) {
//         elements.resize(row, vector<long long>(col, 0));
//     };

//     Matrix &operator*=(const Matrix &other) {
//         Matrix result(row, other.col);
//         for (size_t i = 0; i < result.row; i++) {
//             for (size_t j = 0; j < result.col; j++) {
//                 for (size_t k = 0; k < col; k++) {
//                     result.elements[i][j] += elements[i][k] * other.elements[k][j];
//                 }
//             }
//         }
//         return (*this = result);
//     }

//     static auto element_sum(const Matrix &mat) -> long long {
//         auto sum = 0LL;
//         for (const auto &row : mat.elements)
//             for (const auto &ele : row) sum = (sum + ele);
//         return sum;
//     }
//     static auto identity(size_t size) -> Matrix {
//         Matrix i(size, size);
//         for (size_t j = 0; j < size; j++) i.elements[j][j] = 1;
//         return i;
//     }
// };

// Matrix operator*(const Matrix &A, const Matrix &B) {
//     Matrix result(A);
//     return result *= B;
// }

// class Solution {
// public:
//     int tribonacci(int n) {
//         if (n <= 1) return n;
//         Matrix initial(3, 1);
//         initial.elements[0][0] = initial.elements[1][0] = 1;
//         Matrix transform(3, 3);
//         transform.elements = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
//         Matrix result = transform;
//         n -= 3;
//         while (n) {
//             if (n & 1) result *= transform;
//             transform *= transform;
//             n >>= 1;
//         }
//         initial *= result;
//         return initial.elements[0][0];
//     }
// };