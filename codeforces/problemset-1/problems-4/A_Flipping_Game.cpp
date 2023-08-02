#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, sum=0;
    int ans = 0;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x, sum += x;
    vector<int> prefix(n, 0);
    prefix[0] = v[0];
    for(int i=1; i<n; i++) prefix[i] = v[i] + prefix[i-1];

    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int len = j-i+1;
            int curr = prefix[j];
            if(i > 0) curr -= prefix[i-1];
            ans = max(ans, sum + len - 2*curr);
        }
    }

    cout << ans << '\n';
    return 0;
}