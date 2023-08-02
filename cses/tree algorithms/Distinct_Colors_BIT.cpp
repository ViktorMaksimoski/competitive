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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

struct BIT {
    int n;
    vector<int> tree;
    vector<int> v;

    BIT(int n) : n(n+1), tree(n+1, 0), v(n+1) {}

    void update(int x, int d) {
        v[x] += d;
        for(x++; x<n; x+=x&-x) tree[x] += d;
    } 

    int query(int p) {
        int ans = 0;
        for(p++; p>0; p-=p&-p) ans += tree[p];
        return ans;
    }

    int query(int a, int b) {
        return query(b) - query(a);
    }
};

vector<int> euler, color, lend;
vector<vector<int> > graph;
int timer = 0;

void dfs(int u, int p) {
    lend[u] = timer;

    for(int &v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
    }

    euler[timer] = u;
    timer++;
}

int32_t main() {
    setIO();

    int n;
    cin >> n;

    graph.resize(n+1);
    euler.resize(n, 0);
    lend.resize(n+1, 0);
    color.resize(n+1, 0);

    for(int i=1; i<=n; i++) cin >> color[i];

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    BIT bit(n+1);
    vector<int> res(n+1, 0);
    map<int, int> occ;

    for (int i=0; i<n; i++) {
		if (occ.count(color[euler[i]]))
			bit.update(occ[color[euler[i]]], -1);
		occ[color[euler[i]]] = i;
		bit.update(i, 1);
	
		res[euler[i]] = bit.query(i) - bit.query(lend[euler[i]] - 1);
	}

    for(int i=1; i<=n; i++)
        cout << res[i] << " ";
    return 0;
}