#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <climits>

#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

vector<vector<int> > graph;
vector<int> euler, in, out, val;
int timer = 0;
int n, k, mx=0;
int block;

void dfs(int u, int p) {
    in[u] = timer;
    euler[timer++] = u;
    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
    out[u] = timer;
}

void resize(int n) {
    graph.resize(n);
    val.resize(n);
    euler.resize(n);
    in.resize(n);
    out.resize(n);
}

struct Query {
    int id, L, R, x;

    bool operator<(Query &b) {
        int block_a = L / block;
        int block_b = b.L / block;
        if(block_a != block_b)
            return (block_a < block_b);
        return (R < b.R);
    }
};

void input() {
    cin >> n >> k;
    block = static_cast<int>(sqrt(n));
    resize(n);
    for(int &x : val) cin >> x, mx = max(mx, x);

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void mo() {
    dfs(0, 0);
    vector<Query> queries;
    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        queries.pb(Query{i, in[a], out[a]-1, b});
    }
    sort(all(queries));

    int l=0, r=-1;
    vector<int> cnt(n+1, 0);
    vector<int> freq(mx+1, 0);
    vector<int> ans(k, 0);

    for(Query &q : queries) {
        while(r < q.R) {
            r++;
            freq[val[euler[r]]]++;
            cnt[freq[val[euler[r]]]]++;
        }
        while(r > q.R) {
            cnt[freq[val[euler[r]]]]--;
            freq[val[euler[r]]]--;
            r--;
        }
        while(l < q.L) {
            cnt[freq[val[euler[l]]]]--;
            freq[val[euler[l]]]--;
            l++;
        }
        while(l > q.L) {
            l--;
            freq[val[euler[l]]]++;
            cnt[freq[val[euler[l]]]]++;
        }

        if(q.x > n) ans[q.id] = 0;
        else ans[q.id] = cnt[q.x];
    }

    for(int &x : ans) cout << x << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    input();
    mo();

    return 0;
}