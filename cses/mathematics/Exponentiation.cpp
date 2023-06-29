#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}

struct Combinatorics {
    vector<ll> fac, inv;
    int n, m;

    Combinatorics(int n, int m) {
        fac.resize(n+1, 0);
        inv.resize(n+1, 0);
        this->n = n; this->m = m;
        factorial();
        inverse();
    }

    void factorial() {
        fac[0] = 1;
        for(int i=1; i<=n; i++)
            fac[i] = i * fac[i-1] % m;
    }

    ll exp(ll a, ll b) {
        ll ans = 1;
        a %= m;

        while(b > 0) {
            if(b & 1) ans = ans * a % m;
            a = a * a % m;
            b /= 2;
        }
        return ans;
    }

    void inverse() {
        inv[n] = exp(fac[n], m-2);
        for(int i=n; i>=1; i--)
            inv[i-1] = inv[i] * i % m;
    }

    ll choose(ll a, ll b) {
        return fac[a] * inv[b] % m * inv[a-b] % m;
    }

    ll getFac(int a) {
        return fac[a];
    }

    ll getInv(int a) {
        return inv[a] % m;
    }
};

int main() {
    setIO();

    int q;
    cin >> q;
    Combinatorics comb(int(2 * 1e5), mod);

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << comb.exp(a, b) % mod << '\n';
    }

    return 0;
}