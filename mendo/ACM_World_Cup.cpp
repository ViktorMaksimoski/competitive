#include <bits/stdc++.h>
#define int long long
using namespace std; 
using ll = long long;
   
struct TV { 
    int P, R, M, A;
    bool operator<(TV &t) { return A < t.A; }
} v[30001];
  
ll dp[30001];
void solve() {
    int N, S, E, ans = 0;
    cin >> N >> S >> E;
   
    v[0] = {0, 0, 0, 0};
    for(int i=1; i<=N; i++) cin >> v[i].P >> v[i].R >> v[i].M >> v[i].A;
    sort(v + 1, v + N + 1);
   
    dp[0] = S;
    vector<short> pos(1);
   
    for(int i=1; i<=N; i++) {
        dp[i] = -1;
        for(short &x : pos)
            dp[i] = max(dp[i], v[x].R + dp[x] + (v[i].A - v[x].A - 1) * v[x].M - v[i].P);
        if(dp[i] > -1) pos.push_back(i);
    }
   
    for(short &x : pos)
       ans = max(ans, dp[x] + (E - v[x].A) * v[x].M + v[x].R);
    cout << ans << '\n';
}
   
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   
    int t;
    cin >> t;
       
    while(t--) solve();
   
    return 0;
}