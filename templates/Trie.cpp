#include <bits/stdc++.h>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

/*!for each node we want to know:
//!@param |prefixes| for how many words this node is a prefix
//!@param |words| how many words with some value are in the trie
//!@param |child(dynamically-alocated)| conatins up to 26 relations to longer word that conatins this node
*/
struct Node {
    int prefixes;
    int words;

    struct Node *child[26];
};

//! @return dynamically initalizes an empty node
struct Node *createNode() {
    struct Node *node = new Node();
    node->prefixes = 0;
    node->words = 0;

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

    curr->words++;
}

//! traverses the trie to find a given word
//! if there isn't any, return 0
int countWords(Node *root, string word) {
    struct Node *curr = root;

    for(int i=0; i<word.size(); i++) {
        int id = word[i] - 'a';

        if(!curr->child[id])
            return 0;

        curr = curr->child[id];
    }

    return curr->words;
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

int main() {
    setIO();

    struct Node *root = createNode();
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        insertWord(root, s);
    } 

    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        string s;
        cin >> s;
        cout << countPrefixes(root, s) << '\n';
    }

    return 0;
}