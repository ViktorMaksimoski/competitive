#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}

struct Node {
    int prefixes;
    int words;
    bool isWord;

    struct Node *child[26];
};

//! @return dynamically initalizes an empty node
struct Node *createNode() {
    struct Node *node = new Node();
    node->prefixes = 0;
    node->words = 0;
    node->isWord = false;

    for(int i=0; i<26; i++)
        node->child[i] = NULL;

    return node;
}

//! adds a new word to the tree
void insertWord(Node *root, string word) {
    struct Node *curr = root;

    for(int i=0; i<word.size(); i++) {
        int id = word[i] - 'a';
        if(!curr->child[id])
            curr->child[id] = createNode();

        curr->prefixes++;
        curr = curr->child[id];
    }

    curr->isWord = true;
    curr->words++;
}

//! traverses the trie to find a given word
//! if there isn't any, return 0
bool findWord(Node *root, string word) {
    struct Node *curr = root;

    for(int i=0; i<word.size(); i++) {
        int id = word[i] - 'a';

        if(!curr->child[id])
            return 0;

        curr = curr->child[id];
    }

    return curr->isWord;
}

//! traverses a trie and count the nodes of the prefix's subtrie
int countPrefixes(Node *root, string prefix) {
    struct Node *curr = root;

    for(int i=0; i<prefix.size(); i++) {
        int id = prefix[i] - 'a';

        if(!curr->child[id])
            return 0;

        curr = curr->child[id];
    }

    return curr->prefixes;
}

int n, m;
vector<vector<char> > mat;
bool vis[13][13];
set<string> found;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

bool ok(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

struct Node *root = createNode();

void dfs(int r, int c, string curr) {
    curr += mat[r][c];
    //cout << "(" << r << ", " << c << ") -> " << curr << '\n';

    if(findWord(root, curr)) found.insert(curr);
    if(!countPrefixes(root, curr)) return;

    for(int i=0; i<4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];

        if(ok(newR, newC)) {
            dfs(newR, newC, curr);
        }
    }

}

int main() {
    setIO();

    cin >> n >> m;
    mat.resize(n, vector<char>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> mat[i][j];

    int k;
    cin >> k;
    vector<string> words(k);
    for(string w : words) cin >> w, insertWord(root, w);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            memset(vis, 0, sizeof(vis));
            dfs(i, j, "");
        }
    }

    for(const string &w : found)
        cout << w << '\n';
    return 0;
}