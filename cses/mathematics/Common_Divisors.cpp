#include <iostream>
using namespace std;
const int maxn = 1e6 + 5;

int cnt[maxn+1];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int ans = 0;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        
        for(int i=1; i*i<=x; i++) {
            if(x % i > 0) continue;
            if(cnt[i] > 1 && cnt[x/i] > 1) continue;
            cnt[i]++;
            if(x != i*i) cnt[x/i]++;

            if(cnt[i] > 1) ans = max(ans, i);
            if(cnt[x/i] > 1) ans = max(ans, x/i);
        }
    }

    cout << ans << '\n';
    return 0;
}