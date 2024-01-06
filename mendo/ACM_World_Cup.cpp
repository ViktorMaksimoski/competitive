#include <bits/stdc++.h>
#define int long long
using namespace std; 
using ll = long long;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { 
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
    
struct TV { 
    int P, R, M, A;
    bool operator<(TV &t) { return A < t.A; }
} v[30005];
   
ll dp[30005];
void solve() {
    int N, S, E, ans = 0;
    cin >> N >> S >> E;
    
    v[0] = {0, 0, 0, 0};
    for(int i=1; i<=N; i++) cin >> v[i].P >> v[i].R >> v[i].M >> v[i].A;
    sort(v + 1, v + N + 1);
    
    LineContainer lc;

    dp[0] = S;
    lc.add(0, dp[0]);
    for(int i=1; i<=N; i++) {
        dp[i] = -1;
        dp[i] = max(dp[i], lc.query(v[i].A) - v[i].P);
        if(dp[i] != -1) lc.add(v[i].M, (v[i].R + dp[i]) - (v[i].A + 1) * v[i].M);
    }
    
    for(int x=0; x<=N; x++)
       if(dp[x] != -1) ans = max(ans, dp[x] + (E - v[x].A) * v[x].M + v[x].R);
    cout << ans << '\n';
}
    
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
        
    while(t--) solve();
    
    return 0;
}