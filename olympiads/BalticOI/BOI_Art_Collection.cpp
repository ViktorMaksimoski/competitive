#include <bits/stdc++.h>
#include "art.h"
using namespace std;

void solve(int N) {
    vector<int> inv(N+1);

    for(int i=1; i<=N; i++) {
        vector<int> v;

        for(int j=i; j<=N; j++) v.push_back(j);
        for(int j=1; j<=i-1; j++) v.push_back(j);

        inv[i-1] = publish(v);
    }

    vector<int> ans(N);
    inv[N] = inv[0];
    for(int i=0; i<N; i++)
        ans[(inv[i] - inv[i+1] + N - 1) / 2] = i+1; 
    answer(ans);
}