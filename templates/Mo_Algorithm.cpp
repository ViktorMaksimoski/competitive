#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>

#define pb push_back
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;
using ll = long long;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int block;

//mo's sort implemented
struct Query {
    int left;
    int right;
    int id;

    //makes transition between segments fast
    bool operator<(Query &b) {
        int block_a = left / block;
        int block_b = b.left / block;
        if(block_a != block_b)
            return block_a < block_b;
        return right < b.right;
    }
};

int32_t main() {
    setIO();

    int n, q;
    int mx = 0;
    cin >> n >> q;
    block = static_cast<int>(sqrt(n));

    vector<int> v(n);
    vector<Query> queries(q);

    for(int &x : v) cin >> x, mx = max(mx, x);

    for(int i=0; i<q; i++) {
        cin >> queries[i].left >> queries[i].right;
        queries[i].left--, queries[i].right--;
        queries[i].id = i;
    }

    sort(all(queries));

    ll ans = 0;
    vector<ll> res(q);
    vector<int> occ(mx+1, 0);

    auto update = [&](int x, int type) {
        ans -= (occ[x] * occ[x] * x);
        if(type == 1) occ[x]++;
        else if(type == -1) occ[x]--;
        ans += (occ[x] * occ[x] * x);
    };

    int l=0, r=-1;
    for(int i=0; i<q; i++) {
        int a = queries[i].left;
        int b = queries[i].right;

        while(r < b) {
            r++;
            update(v[r], 1);
        }
        while(r > b) {
            update(v[r], -1);
            r--;
        }
        while(l < a) {
            update(v[l], -1);
            l++;
        }
        while(l > a) {
            l--;
            update(v[l], 1);
        }

        res[queries[i].id] = ans;
    }

    for(ll &x : res)
        cout << x << '\n';
    return 0;
}