#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void setUSA(string name) {
    freopen( (name + ".in").c_str(), "r", stdin);
    freopen( (name + ".out").c_str(), "w", stdout);
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    if(name != "") setUSA(name);
}

int n;
const double ME = 10e-7;
vector<double> pos, speed;
double best = 1e10;

int check(double mid) {
    int s = 0;
    double ans = 0;
    bool left=0, right=0;

    for(int i=0; i<n; i++) {
        if(pos[i] == mid) continue;
        double time = abs(mid - pos[i]) / speed[i];
        
        if(time > ans) {
            left=0, right=0;
            if(pos[i] > mid) right = 1;
            else left = 1;
            ans = time;
        } else if(time == ans) {
            if(pos[i] > mid) right = 1;
            else left = 1;
        }
    }

    best = ans;
    if(left && right) s = 0;
    else if(left) s = -1;
    else s = 1;
    return s;
}

int main() {
    setIO();

    cin >> n;
    double ans = 1e10, r=0;
    pos.resize(n); speed.resize(n);
    for(double &x : pos) cin >> x, r=max(r, x);
    for(double &x : speed) cin >> x;

    double l=0;
    while(r - l > ME) {
        double mid = (l + r) / 2;

        int side = check(mid);
        ans = min(ans, best);

        if(side == 0) break;
        else if(side == -1) r = mid;
        else l = mid;
    }
    
    cout << setprecision(12) << fixed << ans << '\n';
    return 0;
}