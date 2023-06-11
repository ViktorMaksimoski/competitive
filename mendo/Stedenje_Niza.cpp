#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
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

    int n, q, maxQ = 0;
    ll sum = 0;
    cin >> n >> q;

    multiset<ll> ms;
    vector<int> queries(q);
    vector<ll> ans;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        sum += x;
        ms.insert(x);
    }

    for(int i=0; i<q; i++) {
        cin >> queries[i];
        maxQ = max(queries[i], maxQ);
    }

    ans.resize(maxQ+1, -1);
    vector<int> sortedQueries(queries);
    sort(sortedQueries.begin(), sortedQueries.end());

    //cout << "last query: " << maxQ << '\n';
    int last = 0;
    for(int &q : sortedQueries) {
        for(int i=1; i<=q-last; i++) {
            ll diff = *(--ms.end()) - *ms.begin();
            sum += diff;
            sum -= (*ms.begin() + *(--ms.end()));
            ms.erase(ms.begin());
            ms.erase(--ms.end());
            ms.insert(diff);
        }
        last = q;
        ans[q] = sum;
        //cout << ans[q] << '\n';
    }

    for(int &q : queries) cout << ans[q] << '\n';
    return 0;
}