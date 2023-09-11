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
    bool isNumber;
    int cnt;
    map<int, Node*> child;

    Node() : isNumber(false), cnt(0) {}
};

struct Trie {
    Node *root;

    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }

    void insert(int &num) {
        Node *curr = root;

        for(int i=30; i>=0; i--) {
            int bit = ((num & (1 << i)) > 0);
            if(!curr->child.count(bit))
                curr->child[bit] = new Node();
            curr = curr->child[bit];
            curr->cnt++;
        }

        curr->isNumber = true;
    }

    bool search(int &num) {
        Node *curr = root;

        for(int i=30; i>=0; i--) {
            int bit = ((num & (1 << i)) > 0);
            if(!curr->child.count(bit))
                return false;
            curr = curr->child[bit];
        }

        return curr->isNumber;
    }

    void del(int &num) {
        if(!search(num)) return ;
        Node *curr = root;

        for(int i=30; i>=0; i--) {
            int bit = ((num & (1 << i)) > 0);
            curr = curr->child[bit];
            curr->cnt--;
        }

        curr->isNumber = false;
    }

    int minXor(int &num) {
        Node *curr = root;
        int ans = 0;

        for(int i=30; i>=0; i--) {
            int bit = ((num & (1 << i)) > 0);

            if(curr->child.count(bit) && curr->child[bit]->cnt > 0) {
                curr = curr->child[bit];
            } else {
                ans += (1 << i);
                if(!curr->child.count(1-bit))
                    curr->child[1-bit] = new Node();
                curr = curr->child[1-bit];
            }
        }

        return ans;
    }
};

int32_t main() {
    setIO();

    int q;
    cin >> q;

    Trie trie;
    while(q--) {
        int t, a;
        cin >> t >> a;

        if(t == 0) {
            if(!trie.search(a))
                trie.insert(a);
        } else if(t == 1) {
            if(trie.search(a))
                trie.del(a);
        } else {
            cout << trie.minXor(a) << '\n';
        }
    }

    return 0;
}