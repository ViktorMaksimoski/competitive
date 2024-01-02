#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct Node {
    int cnt;
    unordered_map<char, Node*> child;
    Node() : cnt(0) {}
};

struct Trie {
    Node* root;

    Trie() { root = new Node(); }
    ~Trie() { delete root; }

    void insert(string &word) {
        Node* curr = root;
        for(char &ch : word) {
            if(!curr->child.count(ch))
                curr->child[ch] = new Node();
            curr->cnt++;
            curr = curr->child[ch];
        }

        curr->cnt++;
    }

    int count(string &word) {
        Node* curr = root;
        for(char &ch : word) {
            if(!curr->child.count(ch)) return 0;
            curr = curr->child[ch];
        }
        return curr->cnt;
    }
};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;
    Trie trie;

    while(n--) {
        string s;
        cin >> s;
        trie.insert(s);
    }

    while(q--) {
        string s;
        cin >> s;
        cout << trie.count(s) << '\n';
    }

    return 0;
}