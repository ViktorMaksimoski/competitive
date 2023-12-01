#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ans;
    cin >> ans;
    return ans;
}

void print(vector<int> &v) {
    cout << "! ";
    for(int &x : v) cout << x << " ";
    cout << endl;
}

int32_t main() {
    setIO();

    int n;
    cin >> n;
    vector<int> ans(n, 0);

    int q1 = ask(1, 2);
    int q2 = ask(2, n);
    int q3 = ask(1, n);
    int abc = (q1 + q2 + q3) / 2;
    ans[0] = abc - q2;
    ans[1] = abc - q3;
    ans[n-1] = abc - q1;

    for(int i=2; i<n-1; i++) {
        int q = ask(i+1, n);
        ans[i] = q - ans[n-1];
    }

    print(ans);
    return 0;
}