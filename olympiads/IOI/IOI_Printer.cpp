#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;

struct Node {
    bool isWord;
    int chars;
    map<char, Node*> child;

    Node() : isWord(false), chars(0) {}
};

bool cmp(pair<Node*, char> a, pair<Node*, char> b) {
    return a.first->chars < b.first->chars;
}

struct Trie {
    Node* root;
    int totalWords;
    string dfsAns;
    int totalOp;
    int foundSoFar;

    Trie() {
        root = new Node();
        totalWords = 0;
        dfsAns = "";
        totalOp = 0;
    }

    ~Trie() {
        delete root;
    }

    void insert(string &word) {
        Node* curr = root;
        int added = 0;
        for(char &ch : word) {
            if(!curr->child.count(ch))
                curr->child[ch] = new Node();
            curr = curr->child[ch];
            curr->chars = max(curr->chars, sz(word) - added);
            added++;
        }

        curr->isWord = true;
        totalWords++;
    }

    void dfs(Node* curr, char ch) {
        if(ch != ' ') dfsAns += ch, totalOp++;
        if(curr->isWord == true) dfsAns += 'P', totalOp++, foundSoFar++;

        vector<pair<Node*, char> > nextVec;
        for(auto &next : curr->child)
            nextVec.push_back({ next.second, next.first });
        sort(all(nextVec), cmp);

        for(auto &next : nextVec)
            dfs(next.first, next.second);

        if(ch != ' ' && foundSoFar < totalWords) dfsAns += '-', totalOp++;
    }

    void callDFS() {
        foundSoFar = 0;
        dfs(root, ' ');
        cout << totalOp << '\n';
        for(char &ch : dfsAns)
            cout << ch << '\n';
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    Trie trie;

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        trie.insert(s);
    }

    trie.callDFS();
    return 0;
}