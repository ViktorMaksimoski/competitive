#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;

struct Point {
    int t, v;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, l, k;
    cin >> n >> l >> k;

    vector<Point> x(n), y(n);
    for(Point &p : x) cin >> p.t >> p.v;
    for(Point &p : y) cin >> p.t >> p.v;

    vector<bool> vis_a(n+1, 0), vis_b(n+1, 0);
    
    for(int i=0; i<k; i++) {
    double lb=0, rb=2e9;
    double error_bound = 1;
    double eps = 10e-10;
    while(rb - lb > eps) {
        double mid = lb + double(rb - lb) / 2;
        int a, b;
        double dist_x=0, dist_y=l;

        for(int i=0; i<n; i++) {
            if(vis_a[i]) continue;
            double newDist = double(mid - x[i].t) * x[i].v;
            if(newDist > dist_x) {
                dist_x = newDist;
                a = i+1;
            }
        }

        for(int i=0; i<n; i++) {
            if(vis_b[i]) continue;
            double newDist = l - double(mid - y[i].t) * y[i].v;
            if(newDist < dist_y) {
                dist_y = newDist;
                b = i+1;
            }
        }
        
        // a, b se 1-indeksirani
        if(abs(dist_x - dist_y) <= error_bound) {
            cout << a << " " << b << '\n';
            vis_a[a-1] = true;
            vis_b[b-1] = true;
            break;
        } else if(dist_x > dist_y) rb = mid;
        else if(dist_x < dist_y) lb = mid;
    }
    }

    return 0;
}