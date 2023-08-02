#include <bits/stdc++.h>
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
    int val;
    Node *prev, *next;
    Node(int val, Node *prev, Node *next) : val(val), prev(prev), next(next) {}
    ~Node() {
        delete prev;
        delete next;
    }
};

struct BIT {
    int n;
    vector<ll> bit;

    BIT(int n) : n(n), bit(n, 0) {}

    ll query(int p) {
        ll ans = 0;
        for(p++; p>0; p-=p&-p) ans += bit[p];
        return ans;
    }

    void update(int p, int v) {
        for(p++; p<n; p+=p&-p) bit[p] += v;
    }
};


int main() {
    setIO();

    int n;
    cin >> n;
    vector<Node*> row(n);
    vector<int> ans(n, 0);
    vector<int> v(n);
    BIT bit(n+1);
    Node *a, *b;

    for (int i=0; i<n; i++) {
        char ch;
        cin >> ch;
        
        if (i == 0) {
            a = new Node(i, nullptr, nullptr);
            row[i] = a;
            b = a;
            continue;
        }

        if (ch == 'K') {
            b->next = new Node(i, b, nullptr);
            b = b->next;
            row[i] = b;
            continue;
        } 
        
        if(ch == 'P') {
            int pos;
            cin >> pos;

            Node* t = row[pos-1];
            Node* u = new Node(i, t->prev, t);

            if (u->next != nullptr) u->next->prev = u;
            if (u->prev != nullptr) u->prev->next = u;
            if (t == a) a = u;

            row[i] = u;
            continue;
        }
    }

    int id = 0;
    Node* curr = a;
    while (curr != nullptr) {
        v[id] = curr->val;
        curr = curr->next;
        id++;
    }

    for (int i=0; i<n; i++) {
        ans[v[i]] = bit.query(v[i]) + 1;
        bit.update(v[i], 1);
    }

    for (int &x : ans) cout << x << '\n';
    return 0;
}