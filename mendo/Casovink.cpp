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

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    string start = a + b;
    string target = c + d;

    map<string, int> vis;
    map<string, int> dist;
    queue<string> q;

    vis[start] = true;
    dist[start] = 0;
    q.push(start);

    auto incHour = [&](string curr) {
        string ans = curr;

        int x = 10 * (curr[0] - '0') + (curr[1] - '0');
        x++;

        if(x == 24) x = 0;

        if(x == 0) {
            ans[0] = '0';
            ans[1] = '0';
        } else {
            ans[0] = (x / 10) + '0';
            ans[1] = (x % 10) + '0';
        }

        return ans;
    };

    auto decHour  = [&](string curr) {
        string ans = curr;

        int x = 10 * (curr[0] - '0') + (curr[1] - '0');
        x--;

        if(x == -1) x = 23;

        if(x == 0) {
            ans[0] = '0';
            ans[1] = '0';
        } else {
            ans[0] = (x / 10) + '0';
            ans[1] = (x % 10) + '0';
        }

        return ans;
    };

    auto incMin = [&](string curr) {
        string ans = curr;

        int x = 10 * (curr[2] - '0') + (curr[3] - '0');
        x++;

        if(x == 60) x = 0;

        if(x == 0) {
            ans[2] = '0';
            ans[3] = '0';
            ans = incHour(ans);
        } else {
            ans[2] = (x / 10) + '0';
            ans[3] = (x % 10) + '0';
        }

        return ans;
    };

    auto decMin = [&](string curr) {
        string ans = curr;

        int x = 10 * (curr[2] - '0') + (curr[3] - '0');
        x--;

        if(x == -1) x = 59;

        if(x == 0) {
            ans[2] = '0';
            ans[3] = '0';
            ans = decHour(ans);
        } else {
            ans[2] = (x / 10) + '0';
            ans[3] = (x % 10) + '0';
        }

        return ans;
    };

    while(!q.empty()) {
        string u = q.front();
        q.pop();

        //cout << u << " " << dist[u] << '\n';

        if(u == target) {
            cout << dist[u] << '\n';
            return 0;
        }

        for(int i=0; i<4; i++) {
            string v = "";
            if(i == 0) v = incHour(u);
            else if(i == 1) v = decHour(u);
            else if(i == 2) v = incMin(u);
            else v = decMin(u);

            if(vis[v] == 1 || v == "") continue;
            vis[v] = 1;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    return 0;
}