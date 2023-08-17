#pragma GCC target("popcnt")
#include <bits/stdc++.h>

#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct hsh {
	size_t operator()(const pii &p) const {
		return p.first * 239 + p.second;
	}
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int fx, fy;
    cin >> fx >> fy;

    vector<pii> points(n);
    for(pii &pt : points) cin >> pt.first >> pt.second;

    auto meet = [&](int l, int r) -> vector<vector<pii> > {
        int len = r - l + 1;
        vector<vector<pii> > res(r-l+2);

        for(int s=0; s<(1<<len); s++) {
            int px=0, py=0;

            for(int j=0; j<len; j++) {
                if(s & (1 << j)) {
                    px += points[l+j].first;
                    py += points[l+j].second;
                }
            }

            res[__builtin_popcount(s)].push_back({ px, py });
        }

        for(vector<pii> &vec : res) {
            sort(all(vec));
        }
        return res;
    };

    vector<vector<pii> > left = meet(0, n/2-1);
    vector<vector<pii> > right = meet(n/2, n-1);

    unordered_map<pii, map<int, int>, hsh> leftOcc;

    for(int i=0; i<left.size(); i++) {
        for(pii &x : left[i]) {
            leftOcc[x][i]++;
        }
    }

    ll ans[n+1];
    memset(ans, 0, sizeof(ans));

    for(int i=0; i<right.size(); i++) {
        //cout << i << ": \n";
        for(pii &x : right[i]) {
            auto it = leftOcc.find({ fx-x.first, fy-x.second });
            if(it == leftOcc.end()) continue;
            for(auto &pos : it->second)
                ans[i + pos.first] += pos.second;
        }
    }

    for(int i=1; i<=n; i++)
        cout << ans[i] << '\n';
    return 0;
}