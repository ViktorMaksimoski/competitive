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

    int n;
    string s;
    cin >> n >> s;

    int letters = 0;
    set<char> se;
    for(int i=0; i<n; i++) {
        if(!se.count(s[i])) letters++, se.insert(s[i]);
    } 

    map<char, ll> prefix[n+1];
    for(int i=0; i<n; i++) {
        for(const char &let : se) prefix[i+1][let] = prefix[i][let];
        prefix[i+1][s[i]]++; 
    }


    ll ans = 0;
    if(se.size() != 2) {
    for(int len=se.size(); len<n; len++) {
        for(int i=0; i+len-1<n; i++) {
            bool ok = true;
            int val = -1;
            for(const char &ch : se) {
                if(prefix[i+len][ch] - prefix[i][ch] == 0) {
                    ok = false;
                    break;
                }
                if(val == -1) val = prefix[i+len][ch] - prefix[i][ch];
                else if(prefix[i+len][ch] - prefix[i][ch] != val) {
                    ok = false;
                    break;
                }
            }
            ans += ok;
            //if(ok) cout << i << " " << i+len-1 << '\n';
        }
    }
    } else {
        vector<int> v(n, 0);
        for(int i=0; i<n; i++) {
            if(s[i] == *se.begin()) v[i] = 1;
            else if(s[i] == *se.rbegin()) v[i] = -1;
        }
        int sums[n+1] = {0};
        map<int, int> sumsOcc;
        sumsOcc[0] = 1;

        for(int i=0; i<n; i++) {
            sums[i+1] = sums[i] + v[i];
            sumsOcc[sums[i+1]]++;
        }

        for(auto &x : sumsOcc)
            ans += 1ll * (x.second * (x.second - 1)) / 2;
    }

    cout << ans << '\n';
    return 0;
}