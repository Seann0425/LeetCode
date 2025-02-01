#include <bits/stdc++.h>
using namespace std;

class Trie {
    array<Trie *, 26> children{nullptr};
    bool is_end;
public:
    Trie() {
        children.fill(nullptr);
        is_end = false;
    }

    void insert(string word) {
        Trie *cur = this;
        for (const auto &character : word) {
            if (!(cur->children[character - 'a'])) cur->children[character - 'a'] = new Trie();
            cur = cur->children[character - 'a'];
        }
        cur->is_end = true;
        return;
    }

    bool search(string word) {
        Trie *cur = this;
        for (const auto &character : word) {
            if (!(cur->children[character - 'a'])) return false;
            cur = cur->children[character - 'a'];
        }
        return cur->is_end;
    }

    bool startsWith(string prefix) {
        Trie *cur = this;
        for (const auto &character : prefix) {
            if (!(cur->children[character - 'a'])) return false;
            cur = cur->children[character - 'a'];
        }
        return true;
    }
};