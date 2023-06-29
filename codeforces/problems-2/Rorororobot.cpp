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

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    vector<int> cols(m);
    vector<vector<int> > table(m+1, vector<int>(21, 0));
    for(int i=0; i<m; i++) cin >> cols[i], table[i][0] = cols[i];

    for(int k=1; k<20; k++)
        for(int i=0; i+(1<<k)-1<m; i++)
            table[i][k] = max(table[i][k-1], table[i+(1<<(k-1))][k-1]);

    function<int(int, int)> query = [&](int a, int b) {
        int len = b - a + 1;
        int k = 0;
        while((1 << (k + 1)) <= len) k++;
        return max(
            table[a][k],
            table[b-(1 << k)+1][k]
        );
    };

    int q;
    cin >> q;
    int a, b, c, d, k;
    while(q--) {
        cin >> a >> b >> c >> d >> k;
        
        if(cols[b-1] >= a) {
            cout << "NO\n";
            continue;
        }

        if(abs(a-c) % k != 0 || abs(b-d) % k != 0) {
            cout << "NO\n";
            continue;
        }

        if(a > c) swap(a, c);
        int left = n - a;
        int jump = (left / k) * k;
        a += jump;

        if(query(min(b, d)-1, max(b, d)-1) >= a) {
			cout << "NO\n";
			continue;
		}

        cout << "YES\n";
    }

    return 0;
}