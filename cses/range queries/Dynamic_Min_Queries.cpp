#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using ll = long long;
#define ii pair<int, int>
using namespace std;
 
void setIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
void setUSA(string name)
{
    string inName = name + ".in";
    string outName = name + ".out";
    freopen(inName.c_str(), "r", stdin);
    freopen(outName.c_str(), "w", stdout);
}
 
vector<int> v, tree;
 
int combine(int a, int b)
{
    return min(a, b);
}
 
void build(int node, int l, int r)
{
    if(l == r)
    {
        tree[node] = v[l];
    }
    else
    {
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
 
        tree[node] = combine(tree[2*node], tree[2*node+1]);
    }
}
 
void update(int node, int l, int r, int id, int val)
{
    if(l == r)
    {
        tree[node] = val;
    }
    else
    {
        int mid = (l + r) / 2;
        if(l <= id && id <= mid)
            update(2*node, l, mid, id, val);
        else
            update(2*node+1, mid+1, r, id, val);
 
        tree[node] = combine(tree[2*node], tree[2*node+1]);
    }
}
 
int query(int node, int tl, int tr, int l, int r)
{
    if(l > r)
        return INT_MAX;
    if(l == tl && r == tr)
        return tree[node];
 
    int tm = (tl + tr) / 2;
 
    return combine(query(2*node, tl, tm, l, min(r, tm)), query(2*node + 1, tm+1, tr, max(l, tm+1), r));
}
 
int main()
{
    setIO();
 
    int n, q;
    cin >> n >> q;
 
    v.resize(n); tree.resize(4*n+1);
 
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
 
    build(1, 0, n-1);
 
    int k, a, b;
    for(int i=0; i<q; i++)
    {
        cin >> k >> a >> b;
        if(k == 1)
        {
            update(1, 0, n-1, a-1, b);
        }
        else
        {
            cout << query(1, 0, n-1, a-1, b-1) << '\n';
        }
    }
 
    return 0;
}