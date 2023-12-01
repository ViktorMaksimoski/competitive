#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, mx = 0;
    cin >> n;
 
    vector<string> words(n), words2(n);
    vector<vector<int> > len(1002);
 
    for(int i=0; i<n; i++) {
        cin >> words[i];
        words2[i] = words[i];
        sort(all(words2[i]));
        mx = max(mx, sz(words[i]));
        len[sz(words[i])].push_back(i);
    }
 
    queue<int> q;
    vector<int> par(n, -1);
    vector<bool> vis(n, 0);
    int curr = -1;
 
    for(int i=0; i<n; i++)
        if(sz(words[i]) == 2) q.push(i), vis[i] = 1, curr = i;
 
    if(curr == -1) {
        cout << "1\nD\n";
        return 0;
    }
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(sz(words[u]) > sz(words[curr])) curr = u;
        if(sz(words[u]) == mx) break;

        for(int &v : len[sz(words[u])+1]) {
            if(vis[v]) continue;
    
            int cnt = 0;
            for(int i=0; i<sz(words[v]); i++) {
                if(words2[v][i] != words2[u][i-cnt]) cnt++;
                if(cnt == 2) break;
            }
 
            if(cnt == 1) {
                vis[v] = 1;
                q.push(v);
                par[v] = u;
            }
        }
    }
 
    cout << sz(words[curr]) << '\n';
    vector<int> ans;
 
    while(par[curr] != -1) {
        ans.push_back(curr);
        curr = par[curr];
    }
 
    ans.push_back(curr);
    cout << words[curr][0] << '\n';
 
    for(int i=sz(ans)-1; i>=0; i--)
        cout << words[ans[i]] << '\n';
    return 0;
}