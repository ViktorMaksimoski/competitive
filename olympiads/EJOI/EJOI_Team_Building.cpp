//This solved subtasks 1-4
//for 51 points!
#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, mx = 0, ones = 0, mp = 0;
    cin >> n >> q;
    vector<int> v(n);

    for(int &x : v) {
        cin >> x;
        mx = max(mx, x);
        ones += (x == 1);
    }

    vector<pii> queries(q);

    for(pii &x : queries) {
        cin >> x.first >> x.second;
        mx = max(mx, x.second);
        mp = max(mp, x.first);
    }

    auto sorting = [&]() {
        ll ans = 0;

        vector<int> v2 = v;
        sort(rall(v2));
        vector<ll> res(n);
        for(int i=0; i<n; i++)
            res.push_back(i * (n - i - 1));
        sort(rall(res));

        int j=0;
        for(int i=0; i<n; i++) {
            ans += v2[i] * res[j];
            j++;
        }

        return ans;
    };

    if(n <= 500 || q <= 10) {
        cout << sorting() << '\n';
        for(int i=0; i<q; i++) {
            v[queries[i].first-1] = queries[i].second;
            cout << sorting() << '\n';
        }
        return 0;
    }

    if(mx <= 1) {
        vector<ll> res(n);
        for(int i=0; i<n; i++)
            res.push_back(i * (n - i - 1));
        sort(rall(res));

        ll ans = 0;
        for(int i=0; i<ones; i++) ans += res[i];

        cout << ans << '\n';

        for(int i=0; i<q; i++) {
            int diff = 0;
            if(v[queries[i].first-1] == 1) diff--;
            if(queries[i].second == 1) diff++;

            if(diff == 1) ans += res[ones];
            else if(diff == -1) ans -= res[ones-1];

            ones += diff;
            v[queries[i].first-1] = queries[i].second;
            cout << ans << '\n';
        }

        return 0;
    }

    return 0;
}