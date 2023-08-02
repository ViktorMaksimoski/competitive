#include <bits/stdc++.h>
#include <unordered_map>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

struct Node {
    int prefixes;
    bool isWord;
    unordered_map<char, Node*> child;

    Node() : prefixes(0), isWord(false) {}
};

struct Trie {
    Node *root;

    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }

    void insert(string &word) {
        Node *curr = root;
        for(char &ch : word) {
            if(!curr->child.count(ch))
                curr->child[ch] = new Node();
            curr->prefixes++;
            curr = curr->child[ch];
        }

        curr->prefixes++;
        curr->isWord = true;
    }

    void del(string &word) {
        if(!search(word)) return ;
        Node *curr = root;
        for(char &ch : word) {
            curr->prefixes--;
            curr = curr->child[ch];
        }

        curr->prefixes--;
        curr->isWord = false;
    }

    bool search(string &word) {
        Node *curr = root;
        for(char &ch : word) {
            if(!curr->child.count(ch)) return false;
            curr = curr->child[ch];
        }

        return curr->isWord;
    }

    int countP(string &word) {
        Node *curr = root;
        for(char &ch : word) {
            if(!curr->child.count(ch)) return 0;
            curr = curr->child[ch];
        }
        return curr->prefixes;
    }
};

int main() {
    setIO();

    

    return 0;
}