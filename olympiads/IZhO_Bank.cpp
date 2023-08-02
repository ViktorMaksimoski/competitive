#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> need(n), money(m);
    for(int &x : need) cin >> x;
    for(int &x : money) cin >> x;

    vector<ll> done(1 << m, -1);
    vector<ll> left(1 << m, -1);
    done[0] = 0, left[0] = 0;

    for(int s=1; s<(1<<m); s++) {
        for(int i=0; i<m; i++) {
            if((s & (1 << i)) && done[s^(1<<i)] >= 0) {
                int total = left[s^(1<<i)] + money[i];
                int want = need[done[s^(1<<i)]];

                if(total == want) {
                    done[s] = 1 + done[s^(1<<i)];
                    left[s] = 0;
                } else if(total < want) {
                    done[s] = done[s^(1<<i)];
                    left[s] = total;
                }

                if(done[s] == n) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}