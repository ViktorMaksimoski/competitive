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

void solve() {
    int n;
	cin>>n;
	vector<int> t;
	set<int> s;
 
	for(int i=1; i*i<=n; i++){
		if(n % i) continue;
        s.insert(i);
        s.insert(n/i);
	}

    string ans(n, ' ');

    for(const auto &x : s) t.pb(x);
	int k;
	for(int i=1; i<sz(t); i++){
		if(t[i] - t[i-1] != 1){
			k = i;
			break;
		}
	}

    for(int i=0; i<=k; i++) {
        char ch = 'a' + i;
        for(int j=i; j<n; j+=k+1){
			ans[j] = ch;
		}
    }

    cout << ans << '\n';
}

int32_t main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}