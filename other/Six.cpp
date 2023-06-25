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

vector<pair<ll, int> > divs;
int ways[(1 << 6)+1];
map<ll, ll> dp[(1<<6) + 1];

void getDiv(ull n) {
    int cnt = 0;
    for(ll i=2; i*i<=n; i++) {
        if(n % i > 0) continue;
        cnt = 0;
        while(n % i == 0 && n >= i) {
            cnt++;
            n /= i;
        }
        divs.push_back({ i, cnt });
    }
    if(n > 1) divs.push_back({ n, 1 });
}

ll sol(int s, ll p) {
    if(dp[s].find(p) != dp[s].end())
        return dp[s][p];

    ll ans = 1;

    for(int i=1; i<(1<<divs.size()); i++) {
        bool ok = true;
        for(int j=0; j<divs.size(); j++) {
            for(int k=j; k<divs.size(); k++) {
                if( (i & (1<<j)) && (i & (1<<k)) && (p & (1ll<<(6*j+k))) ) {
                    ok = false;
                    break;
                }
            }
        }

    if(ok) {
        ll x = 0;

        for(int j=0; j<divs.size(); j++) {
            for(int k=0; k<divs.size(); k++) {
                if((s & (1<<j)) && (i & (1<<k)))
                    x |= (1ll << (6*min(j, k) + max(j, k)));
            }
        }

        ans += sol(s|i, p|x) * ways[i];
        ans %= mod;
    }
    }

    dp[s][p] = ans;
    return ans;
}

int main() {
    setIO();

    ull n;
    cin >> n; 

    getDiv(n);
    memset(ways, 0, sizeof(ways));
    
    //the list can have at most 12 elements(each prime can be used twice)
    for(int i=1; i<(1<<divs.size()); i++) {
        ways[i] = 1;
        for(int j=0; j<divs.size(); j++) {
            if(i & (1 << j)) ways[i] *= divs[j].second;
        }
    }

    cout << (sol(0, 0) - 1) % mod << '\n';
    return 0;
}