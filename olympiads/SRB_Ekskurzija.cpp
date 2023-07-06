#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using ull = unsigned long long;
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

map<int, int> size;
map<int, int> par;

int find(int a) {
    if(a == par[a]) return a;
    return par[a] = find(par[a]);
}

bool uni(int a, int b) {
    a = find(a), b = find(b);

    if(a == b) return 0;

    if(size[a] > size[b]) swap(a, b);
    size[b] += size[a];
    par[a] = b;

    return 1;
}

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    int components = n;

    while(m--) {
        int a, b;
        cin >> a >> b;

        if(!size.count(a))
            size[a] = 1, par[a] = a;
        if(!size.count(b))
            size[b] = 1, par[b] = b;
        
        if(uni(a, b))
            components--;
    }

    cout << components << '\n';
    return 0;
}