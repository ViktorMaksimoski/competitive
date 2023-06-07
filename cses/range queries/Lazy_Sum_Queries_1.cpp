#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;
int LOG = 2;
using namespace std;
 
void setUSA(string name)
{
    string inName = name + ".in";
    string outName = name + ".out";
    freopen(inName.c_str(), "r", stdin);
    freopen(outName.c_str(), "w", stdout);
}
 
void setIO(string name = "")
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(name != "") setUSA(name);
}
 
vector<int> v;
vector<ull> segment;
vector<ll> lazy;
 
void build(int node, int l, int r)
{
    if(l == r) {
        segment[node] = v[l];
    }
    else {
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node + 1, mid+1, r);
 
        segment[node] = segment[2*node] + segment[2*node + 1];
    }
}
 
void update(int node, int tl, int tr, int l, int r, ll val) {
    if(lazy[node] != 0) {
        segment[node] += 1LL * ((tr - tl + 1) * lazy[node]);
        if(tl != tr) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
 
    if(tl > tr || tl > r || tr < l)
        return ;
 
    if(tl >= l && tr <= r) {
        segment[node] += 1LL * ((tr - tl + 1) * val);
        if(tl != tr) {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
 
        return ;
    }
 
    int mid = (tl + tr) / 2;
    update(2*node, tl, mid, l, r, val);
    update(2*node + 1, mid+1, tr, l, r, val);
 
    segment[node] = segment[2*node] + segment[2*node+1];
 
}
 
ull query(int node, int tl, int tr, int l, int r) {
    if(r < tl || tr < l)
        return 0;
 
    if(lazy[node] > 0) {
        segment[node] += 1LL * ((tr - tl + 1) * lazy[node]);
        if(tr != tl) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
 
        lazy[node] = 0;
    }
 
    if(l <= tl && tr <= r)
        return segment[node];
 
    int tm = (tl + tr) / 2;
 
    return 1LL * query(2*node, tl, tm, l, r) + 1LL * query(2*node + 1, tm+1, tr, l, r);
 
}
 
int main()
{
    setIO();
 
    int n, q;
    cin >> n >> q;
 
    v.resize(n);
    segment.resize(4*n + 5);
    lazy.resize(4*n + 5, 0);
    for(int i=0; i<n; i++) cin >> v[i];
 
    build(1, 0, n-1);
 
    while(q--) {
        int x;
        cin >> x;
        if(x == 1) {
            int a, b;
            ll c;
            cin >> a >> b >> c;
            update(1, 0, n-1, a-1, b-1, c);
        } else {
            int a;
            cin >> a;
            cout << query(1, 0, n-1, a-1, a-1) << '\n';
        }
    }
 
    return 0;
}