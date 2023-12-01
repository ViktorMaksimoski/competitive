#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    setIO();

    int A, B, C;
    cin >> A >> B >> C;
    int old_b = B, old_c = C;
    int n = A + B + C;
    string ans(n+1, '.');

    for(int i=0; i<A; i++) {
        int x;
        cin >> x;
        ans[x] = 'A';
    }

    vector<pii> segments;
    segments.push_back({ -1, -1 }); 
    int curr = 1;

    for(int i=1; i<=n; i++) {
        if(ans[i] == 'A') {
            if(curr < i) {
                if((i - curr) % 2 == 1) {
                    segments.push_back({ curr, i-1 });
                } else {
                    char ch = 'B';
                    for(int j=curr; j<i; j++) {
                        ans[j] = ch;
                        if(ch == 'B') B--, ch = 'C';
                        else C--, ch = 'B';
                    }
                }
            }
            curr = i+1;
        }
    }

    if(curr < n+1) {
        if((n + 1 - curr) % 2 == 1) {
            segments.push_back({ curr, n });
        } else {
            char ch = 'B';
            for(int j=curr; j<=n; j++) {
                ans[j] = ch;
                if(ch == 'B') B--, ch = 'C';
                else C--, ch = 'B';
            }
        }
    }

    if(B < 0 || C < 0) {
        cout << -1 << '\n';
        return 0;
    }

    int need_b = 0, need_c = 0;
    for(int i=1; i<sz(segments); i++) {
        int len = segments[i].second - segments[i].first + 1;
        need_b += (len + 1) / 2;
        need_c += len / 2;
    }

    int pos = sz(segments);
    while(need_b > B) {
        pos--;
        need_b--;
        need_c++;
    }    

    if(need_c > C) {
        cout << -1 << '\n';
        return 0;
    }

    for(int i=1; i<sz(segments); i++) {
        char ch = (i >= pos ? 'C' : 'B');
        for(int j=segments[i].first; j<=segments[i].second; j++) {
            ans[j] = ch;
            if(ch == 'B') ch = 'C';
            else ch = 'B';
        }
    }

    int cnt_b = 0, cnt_c = 0;
    for(int i=1; i<=n; i++) {
        if(ans[i] == 'B') cnt_b++;
        else if(ans[i] == 'C') cnt_c++;
    }

    if(cnt_b > old_b || cnt_c > old_c) {
        cout << -1 << '\n';
        return 0;
    }

    for(int i=1; i<=n; i++) cout << ans[i];
    return 0;
}