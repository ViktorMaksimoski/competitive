#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int &x : v) cin >> x;

    int sum = 0;
    int id=1;
    int ans = INT_MAX;
    for(int i=0; i<k; i++) sum += v[i];
    ans = min(ans, sum);

    for(int i=k; i<n; i++) {
        sum -= v[i-k];
        sum += v[i];
        if(sum < ans) {
            ans = sum;
            id = i-k+2;
        }
    }
    
    cout << id << '\n';
    return 0;
}