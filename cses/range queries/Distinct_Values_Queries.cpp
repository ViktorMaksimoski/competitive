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

vector<int> compress(vector<int> &v) {
    set<int> s(all(v));
    return vector<int>(all(s));
}

int block;
struct Query {
    int id;
    int L;
    int R;

    bool operator<(Query &b) {
        int block_a = L / block;
        int block_b = b.L / block;
        if(block_a != block_b)
            return (block_a < block_b);
        return (R < b.R);
    }
};

int32_t main() {
    setIO();

    int n, q;
    cin >> n >> q;
    block = static_cast<int>(sqrt(n));
    vector<int> v(n);
    for(int &x : v) cin >> x;

    vector<int> comp = compress(v);
    vector<int> key(n);
    for(int i=0; i<n; i++)
        key[i] = lower_bound(all(comp), v[i]) - comp.begin();

    vector<Query> queries(q);
    int br=0;
    for(Query &q : queries) {
        cin >> q.L >> q.R;
        q.L--, q.R--;
        q.id = br++;
    }
    sort(all(queries));

    vector<int> ans(q, 0);
    int diff = 0;
    vector<int> occ(n, 0);

    int l=0, r=-1;
    for(Query &q : queries) {
        while(r < q.R) {
            r++;
            occ[key[r]]++;
            if(occ[key[r]] == 1) diff++;
        }
        while(r > q.R) {
            occ[key[r]]--;
            if(occ[key[r]] == 0) diff--;
            r--;
        }
        while(l < q.L) {
            occ[key[l]]--;
            if(occ[key[l]] == 0) diff--;
            l++;
        }
        while(l > q.L) {
            l--;
            occ[key[l]]++;
            if(occ[key[l]] == 1) diff++;
        }
        ans[q.id] = diff;
    }

    for(int &x : ans) cout << x << '\n';
    return 0;
}