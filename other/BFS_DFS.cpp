#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<long long, long long>
#define debug(x) cout << #x << " = " << x << endl
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    setIO();

    int n;
    cin >> n;

    vector<int> bfs(n);
    vector<int> dfs(n);
    vector<pii> edges;

    for(int &x : bfs)
        cin >> x;
    for(int &x : dfs)
        cin >> x;

    if(bfs[1] != dfs[1]) {
        cout << -1 << '\n';
        return 0;
    }

    for(int i=1; i<n; i++) {
        edges.push_back({ bfs[0], bfs[i] });
    }

    for(int i=1; i<n-1; i++) {
        edges.push_back({ dfs[i], dfs[i+1] });
    }

    cout << sz(edges) << '\n';
    for(pii &e : edges)
        cout << e.first << " " << e.second << '\n';
    return 0;
}