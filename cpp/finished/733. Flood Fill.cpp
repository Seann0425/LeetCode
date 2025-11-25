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
    void paint(vector<vector<int>> &img, int rp, int cp, int color, int target) {
        img[rp][cp] = color;
        if (rp > 0 && img[rp - 1][cp] == target) paint(img, rp - 1, cp, color, target);
        if (rp < img.size() - 1 && img[rp + 1][cp] == target) paint(img, rp + 1, cp, color, target);
        if (cp > 0 && img[rp][cp - 1] == target) paint(img, rp, cp - 1, color, target);
        if (cp < img[0].size() - 1 && img[rp][cp + 1] == target) paint(img, rp, cp + 1, color, target);
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int target = image[sr][sc];
        if (target == color) return image;
        paint(image, sr, sc, color, target);
        return image;
    }
};