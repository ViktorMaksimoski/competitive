#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int LOG = 20;

vector<vector<int> > up, graph;
vector<vector<ll> > sum;
vector<pii> v;

void dfs(int u, int p) {
    for(int i=1; i<LOG; i++) {
        up[u][i] = up[ up[u][i-1] ][i-1];
        sum[u][i] = 1ll * (sum[u][i-1] + sum[ up[u][i-1] ][i-1]);
    }

    for(int &next : graph[u]) {
        if(next == p) continue;
         up[next][0] = u;
         sum[next][0] = v[u].second;
         dfs(next, u);
    }
}

int jmp(int a, int b) {
    int currNode = a;
    int currLeft = b;

    currLeft -= v[a].second;

    for(int i=LOG-1; i>=0; i--) {
        if(sum[currNode][i] <= currLeft) {
            currLeft -= sum[currNode][i];
            currNode = up[currNode][i];
        }
    }

    if(currLeft <= 0) return currNode;
    return up[currNode][0];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    graph.resize(n+1);
    up.resize(n+1, vector<int>(LOG, 0));
    sum.resize(n+1, vector<ll>(LOG, 0));

    v.resize(n+1);
    v[0] = {1500000000, 1500000000};
    for(int i=1; i<=n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    stack<pii> curr;
    for(int i=1; i<=n; i++) {
        while(!curr.empty() && curr.top().second < v[i].first) {
            graph[i].push_back(curr.top().first);
            graph[curr.top().first].push_back(i);
            curr.pop();
        }
        curr.push({ i, v[i].first });
    }

    while(!curr.empty()) {
        graph[0].push_back(curr.top().first);
        graph[curr.top().first].push_back(0);
        curr.pop();
    }

    dfs(0, 0);

    while(q--) {
        int a, b;
        cin >> a >> b;

        cout << jmp(a, b) << '\n';
    }

    return 0;
}