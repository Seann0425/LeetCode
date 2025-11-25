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
    struct UsingRoom {
        unsigned start;
        unsigned end;
        int roomNumber;
        UsingRoom(unsigned s, unsigned e, int r) : start(s), end(e), roomNumber(r){};
    };

    struct roomCmp {
        bool operator()(const UsingRoom &a, const UsingRoom &b) {
            return a.end > b.end;
        }
    };
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> timesBooked(n, 0);                                    // times that each room be booked
        priority_queue<int, vector<int>, greater<int>> currentEmpty;      // rooms that are currently empty
        priority_queue<UsingRoom, vector<UsingRoom>, roomCmp> usingRooms; // rooms that are currently
        unsigned currentTime = 0;

        // sort meetings by starting time
        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        // initialize currently empty rooms
        for (int i = 0; i < n; i++)
            currentEmpty.push(i);

        for (const auto &meeting : meetings) {
            if (currentTime < meeting[0]) currentTime = meeting[0];

            // update both priority queue to current status
            while (!usingRooms.empty() && usingRooms.top().end <= currentTime) {
                currentEmpty.push(usingRooms.top().roomNumber);
                usingRooms.pop();
            }

            unsigned duration = meeting[1] - meeting[0];
            // if there exist empty rooms
            if (!currentEmpty.empty()) {
                int idx = currentEmpty.top();
                currentEmpty.pop();
                usingRooms.push(UsingRoom(currentTime, currentTime + duration, idx));
                timesBooked[idx]++;
            }
            // if there exist no empty rooms
            else {
                currentTime = usingRooms.top().end;
                while (!usingRooms.empty() && usingRooms.top().end <= currentTime) {
                    currentEmpty.push(usingRooms.top().roomNumber);
                    usingRooms.pop();
                }

                int idx = currentEmpty.top();
                currentEmpty.pop();
                usingRooms.push(UsingRoom(currentTime, currentTime + duration, idx));
                timesBooked[idx]++;
            }
        }

        int most = 0;
        for (int i = 0; i < n; i++)
            if (timesBooked[i] > timesBooked[most]) most = i;
        return most;
    }
};