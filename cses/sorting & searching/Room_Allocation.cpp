#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;
using Node = array<int, 3>;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


int32_t main() {
    setIO();

    int n;
    cin >> n;

    vector<int> ans(n, 0);
    vector<Node> v(n);

    for(int i=0; i<n; i++) {
        v[i][2] = i;
        cin >> v[i][0] >> v[i][1];
    }

    sort(all(v));

    int room = 2;
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    ans[v[0][2]] = 1;
    pq.push({ v[0][1], v[0][0], 1 });

    for(int i=1; i<n; i++) {
        if(v[i][0] > pq.top().at(0)) {
            int x = pq.top().at(2);
            ans[v[i][2]] = x;
            pq.pop();
            pq.push({ v[i][1], v[i][0], x });
        } else {
            ans[v[i][2]] = room++;
            pq.push({ v[i][1], v[i][0], ans[v[i][2]] });
        }
    }

    cout << *max_element(all(ans)) << '\n';
    for(int &x : ans) cout << x << " ";
    return 0;
}