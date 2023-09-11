#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n;
vector<int> a, b;
vector<int> L, R;

void solve_2() {
    int curr = b[0];
    int ans = 0;

    for(int i=0; i<n; i++) {
        if(a[i] != curr) continue;
        ans++;
        int j = i-1;
        while(j >= 0 && a[j] <= curr) j--, ans++;
        j = i+1;
        while(j < n && a[j] <= curr) j++, ans++;
        i = j-1;
    }

    cout << ans << '\n';
}

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) : n(n), tree(4*n+5, 0) {}

    void update(int u, int tl, int tr, int pos, int val) {
        if(tl == tr) {
            tree[u] = max(tree[u], val);
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm)
                update(2*u, tl, tm, pos, val);
            else
                update(2*u+1, tm+1, tr, pos, val);
            tree[u] = max(tree[2*u], tree[2*u+1]);
        }
    }

    int query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) return 0;
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return max(
          query(2*u, tl, tm, l, r),
          query(2*u+1, tm+1, tr, l, r)  
        );
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int32_t main() {
    setIO();

    cin >> n;
    a.resize(n);
    b.resize(n);
    L.resize(n);
    R.resize(n);
    vector<int> temp(n+2, 0);
    set<int> diff;
    map<int, int> comp;

    for(int i=0; i<n; i++) {
        cin >> a[i];
        comp[a[i]] = i;
        temp[i+1] = a[i];
    }

    for(int i=0; i<n; i++) {
        cin >> b[i];
        diff.insert(b[i]);
    }

    if(sz(diff) == 1) {
        solve_2();
        return 0;
    }

    temp[0] = INT_MAX;
    temp[n+1] = temp[0];

    stack<int> st;
    st.push(0);

    for(int i=1; i<=n; i++) {
        while(temp[st.top()] <= temp[i])
            st.pop();
        L[i-1] = st.top() - 1;
        st.push(i);
    }

    while(!st.empty()) st.pop();

    st.push(n+1);
    for(int i=n; i>=1; i--) {
        while(temp[st.top()] <= temp[i])
            st.pop();
        R[i-1] = st.top() - 1;
        st.push(i);
    }
    
    if(n <= 5004) {
        vector<vector<ll> > dp(n+5, vector<ll>(n+5, 0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(a[i-1] == b[j-1] && L[i-1] < j-1 && j-1 < R[i-1])
                    dp[i][j] = dp[i][j-1] + 1;
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }

        cout << dp[n][n] << '\n';
        return 0;
    }

    SegTree tree(n+1);
    for(int i=0; i<n; i++) {
        int ans = 0;
        if(!comp.count(b[i])) continue;
        if(L[comp[b[i]]] < i && R[comp[b[i]]] > i) {
            ans = tree.query(0, comp[b[i]]);
            tree.update(comp[b[i]], ans+1);
        }
    }

    cout << tree.query(0, n-1) << '\n';
    return 0;
}