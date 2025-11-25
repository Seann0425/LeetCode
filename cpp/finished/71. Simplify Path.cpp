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

/*the solution should start from below*/

class Solution {
public:
    string simplifyPath(string path) {
        string simplifiedPath = "";
        int periodCount = 0;
        for (const auto &ch : path) {
            if (ch == '.') {
                if (!simplifiedPath.empty() && simplifiedPath.back() == '/') periodCount++;
                else if (periodCount != 0) periodCount++;
            } else {
                if (ch != '/') periodCount = 0;
                if (periodCount == 1) simplifiedPath.pop_back();
                else if (periodCount == 2) {
                    int slashCount = 0;
                    while (slashCount < 2 && simplifiedPath.size() > 1) {
                        if (simplifiedPath.back() == '/') slashCount++;
                        simplifiedPath.pop_back();
                    }
                }
                periodCount = 0;
            }
            if (ch == '/' && !simplifiedPath.empty() && simplifiedPath.back() == '/') continue;
            simplifiedPath.push_back(ch);
        }
        if (periodCount == 1) simplifiedPath.pop_back();
        else if (periodCount == 2) {
            int slashCount = 0;
            while (slashCount < 2 && simplifiedPath.size() > 1) {
                if (simplifiedPath.back() == '/') slashCount++;
                simplifiedPath.pop_back();
            }
        }
        while (simplifiedPath.back() == '/' && simplifiedPath.size() > 1)
            simplifiedPath.pop_back();
        return simplifiedPath;
    }
};