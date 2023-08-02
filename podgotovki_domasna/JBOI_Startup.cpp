#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int LOG = 20;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<ll> prefix(n+1, 0);
    vector<vector<ll> > table(n+1, vector<ll>(LOG, 0));

    for(int i=0; i<n; i++) {
        cin >> v[i];
        prefix[i+1] = v[i] + prefix[i];
        table[i][0] = prefix[i+1];
    }

    for(int k=1; k<20; k++)
        for(int i=0; i+(1<<k)-1<n; i++)
            table[i][k] = min(table[i][k-1], table[i+(1<<(k-1))][k-1]);

    function<ll(int, int)> query = [&](int a, int b) {
        int len = b-a+1;
        int k=0;
        while((1 << (k+1)) <= len) k++;

        return min(
            table[a][k],
            table[b-(1<<k)+1][k]
        );
    };

    int ans = (query(0, n-1) >= 0);
    for(int i=0; i<n-1; i++) {
        if(query(i+1, n-1) - prefix[i+1] < 0) continue;
        if(query(0, i) + prefix[n] - prefix[i+1] < 0) continue;
        ans++;
    }

    cout << ans << '\n';
    return 0;
}