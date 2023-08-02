#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <stack>
#include <cstring>
#include <chrono>
#include <random>
#include <numeric>
#include <bitset>
#include <array>
#include <functional>
#include <climits>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << ": " << x << '\n'
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int inf = 1e12;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct SegTree {
    int n;
    int ans = 0;
    vector<int> tree;

    SegTree(int n) : n(n), tree(4*n+5, inf) {}

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] = val;
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            tree[u] = min(tree[2*u], tree[2*u+1]);
        }
    }

    void query(int u, int tl, int tr, int l, int r, int val) {
        if(tl > r || l > tr) return ;
        if(tree[u] > val) return ;
        if(tl == tr) {
            tree[u] = inf;
            ans++;
            return ;
        }
        int tm = (tl + tr) / 2;
        query(2*u, tl, tm, l, r, val);
        query(2*u+1, tm+1, tr, l, r, val);
        tree[u] = min(tree[2*u], tree[2*u+1]);
    }

    void query(int l, int r, int val) {
        ans = 0;
        query(1, 0, n-1, l, r, val);
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    int getAns() {
        return ans;
    }
};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;

    SegTree tree(n);
    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int a, b;
            cin >> a >> b;
            tree.update(a, b);
        } else {
            int a, b, c;
            cin >> a >> b >> c;
            tree.query(a, b-1, c);
            cout << tree.getAns() << '\n';
        }
    }

    return 0;
}