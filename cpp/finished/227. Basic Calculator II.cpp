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
public:
    int calculate(string s) {
        stack<int> numbers;
        stack<char> operators;
        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                int MSD = i;
                while (isdigit(s[i]) && i < static_cast<int>(s.size()))
                    i++;
                numbers.push(stoi(s.substr(MSD, i - MSD)));
                i--;
            }
            //* and /
            else if (s[i] == '*') {
                while (!isdigit(s[i]) && i < static_cast<int>(s.size()))
                    i++;
                int MSD = i;
                while (isdigit(s[i]) && i < static_cast<int>(s.size()))
                    i++;
                int b = stoi(s.substr(MSD, i - MSD));
                i--;
                int a = numbers.top();
                numbers.pop();
                numbers.push(a * b);
            } else if (s[i] == '/') {
                while (!isdigit(s[i]) && i < static_cast<int>(s.size()))
                    i++;
                int MSD = i;
                while (isdigit(s[i]) && i < static_cast<int>(s.size()))
                    i++;
                int b = stoi(s.substr(MSD, i - MSD));
                i--;
                int a = numbers.top();
                numbers.pop();
                numbers.push(a / b);
            } else operators.push(s[i]);
        }

        stack<int> newNumbers;
        while (!numbers.empty()) {
            newNumbers.push(numbers.top());
            numbers.pop();
        }
        stack<char> newOperators;
        while (!operators.empty()) {
            newOperators.push(operators.top());
            operators.pop();
        }

        while (!newOperators.empty()) {
            int a = newNumbers.top();
            newNumbers.pop();
            int b = newNumbers.top();
            newNumbers.pop();
            if (newOperators.top() == '+') {
                newNumbers.push(a + b);
            } else {
                newNumbers.push(a - b);
            }
            newOperators.pop();
        }

        return newNumbers.top();
    }
};