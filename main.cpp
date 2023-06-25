#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    long long ans = 0;
    cin >> n;

    vector<Point> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i].x;
    for(int i=0; i<n; i++)
        cin >> v[i].y;

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
           long long X = (v[i].x - v[j].x) * (v[i].x - v[j].x);
           long long Y = (v[i].y - v[j].y) * (v[i].y - v[j].y);
           ans = max(ans, X + Y);
        }
    }

    cout << ans << '\n';
    return 0;
}