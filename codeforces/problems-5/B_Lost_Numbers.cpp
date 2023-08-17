#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ans;
    cin >> ans;
    return ans;
}

void print(vector<int> &v) {
    cout << "! ";
    for(int &x : v)
        cout << x << " ";
    cout << endl;
}

int intersect(pii &a, pii &b) {
    if(a.first == b.first) return a.first;
    if(a.first == b.second) return a.first;
    if(a.second == b.first) return a.second;
    return a.second;
}

int32_t main() {
    setIO();

    map<int, pair<int, int> > prod;
    vector<int> v = {4, 8, 15, 16, 23, 42};

    for(int i=0; i<5; i++)
        for(int j=i+1; j<6; j++)
            prod[v[i] * v[j]] = {v[i], v[j]};

    vector<int> ans(6, 0);
    int q1 = ask(1, 3);
    int q2 = ask(1, 2);
    int num1 = intersect(prod[q1], prod[q2]);
    ans[0] = num1;
    ans[1] = q2 / num1;
    ans[2] = q1 / num1;

    int q3 = ask(4, 6);
    int q4 = ask(4, 5);    
    int num4 = intersect(prod[q3], prod[q4]);
    ans[3] = num4;
    ans[4] = q4 / num4;
    ans[5] = q3 / num4;

    print(ans);
    return 0;
}