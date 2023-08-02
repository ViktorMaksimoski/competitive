#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using ull = unsigned long long;
#define ii pair<int, int>
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

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

void solve() {
    string s[2];
    cin >> s[0] >> s[1];
    int t, q;
    cin >> t >> q;

    int diff = 0;
    for(int i=0; i<sz(s[0]); i++)
        if(s[0][i] != s[1][i]) diff++;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for(int i=0; i<q; i++) {
        while(!pq.empty() && pq.top().first == i) {
            diff += (s[0][pq.top().second] != s[1][pq.top().second]);
            pq.pop();
        }

        int x;
        cin >> x;

        if(x == 1) {
            int p;
            cin >> p;
            diff -= (s[0][p-1] != s[1][p-1]);
            pq.push({ i+t, p-1 });
        } else if(x == 2) {
            int s1, p1, s2, p2;
            cin >> s1 >> p1 >> s2 >> p2;
            s1--, s2--, p1--, p2--;

            if(s[s1][p1] != s[1-s1][p1]) diff--;
            if(s[s2][p2] != s[1-s2][p2]) diff--;

            swap(s[s1][p1], s[s2][p2]);

            if(s[s1][p1] != s[1-s1][p1])diff++;
            if(s[s2][p2] != s[1-s2][p2])diff++;

        } else if(x == 3) {
            cout << (!diff ? "YES" : "NO") << '\n';
        }
    }

}

int main() {
    setIO();

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}