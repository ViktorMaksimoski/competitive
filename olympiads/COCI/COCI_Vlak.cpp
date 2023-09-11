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
    bool isWord;
    vector<int> dp;
    map<char, Node*> child;

    Node() : isWord(false), dp(2, 0) {}
};

struct Trie {
    Node *root;

    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word, int player) {
        Node *curr = root;
        for(char &ch : word) {
            if(!curr->child.count(ch))
                curr->child[ch] = new Node();
            curr = curr->child[ch];
            curr->dp[player] = 1;
        }

        curr->isWord = true;
    }

    bool search(string word) {
        Node *curr = root;

        for(char &ch : word) {
            if(!curr->child.count(ch)) return false;
            curr = curr->child[ch];
        }

        return curr->isWord;
    }

    bool dfs(Node *curr, int turn, char ch) {
        if(!curr->dp[turn] && ch != ' ') return false;
        bool ans = 1;

        for(auto &next : curr->child)
            ans &= dfs(next.second, 1 - turn, next.first);

        return 1 - ans;
    }

    void callDFS() {
        bool ans = dfs(root, 0, ' ');
        if(ans == 1) cout << "Nina\n";
        else cout << "Emilija\n";
    }
};

int32_t main() {
    setIO();

    Trie trie;

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        trie.insert(s, 0);
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        string s;
        cin >> s;
        trie.insert(s, 1);
    }

    trie.callDFS();
    return 0;
}