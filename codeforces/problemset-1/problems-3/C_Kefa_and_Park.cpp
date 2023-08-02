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

#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for(auto &x : v)
#define mp make_pair
#define rep(i, a, b) for(int i=a; i<b; i++)
#define repr(i, a, b) for(int i=a; i>=b; i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n, k;
int ans = 0;
vector<vector<int> > graph;
vector<int> cats;

void dfs(int u, int cnt, int p=-1) {
    int children = 0;
    each(v, graph[u]) {
        if(v == p) continue;
        children++;
    }

    each(v, graph[u]) {
        if(v == p) continue;
        if(cats[v-1] && cnt + 1 <= k) dfs(v, cnt+1, u) ;
        if(!cats[v-1]) dfs(v, 0, u);
    }

    ans += (children == 0);
}

int32_t main() {
    setIO();

    cin >> n >> k;
    graph.resize(n+1);
    cats.resize(n, false);
    each(x, cats) cin >> x;

    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfs(1, cats[0]);

    cout << ans << '\n';
    return 0;
}