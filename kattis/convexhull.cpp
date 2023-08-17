#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<pii> points;
vector<pii> hull;

ll area(pii a, pii b, pii c) {
    ll d1 = (b.first - a.first) * (c.second - a.second);
    ll d2 = (b.second - a.second) * (c.first - a.first);
    return d1 - d2;
}

void monotone_chain() {
    sort(all(points));
    uniq(points);

    int n = sz(points);

    if(n <= 2) {
        hull = points;
        return ;
    }

    for(int i=0; i<n; i++) {
        while(sz(hull) > 1 && area(hull[sz(hull)-2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    auto lower_sz = hull.size();
    for (int i=n-2; i>=0; i--) {
        while(sz(hull) > lower_sz && area(hull[sz(hull)-2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while(n) {
        points.assign(n, {});
        hull.clear();
        for(pii &p : points) cin >> p.first >> p.second;

        monotone_chain();
        cout << sz(hull) << '\n';
        for(pii &p : hull) 
            cout << p.first << " " << p.second << '\n';

        cin >> n;
    }

    return 0;
}