#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string start = "";
    for(int i=0; i<9; i++) {
        int x;
        cin >> x;
        start += char('0' + x);
    }

    unordered_map<string, int> dist;
    dist[start] = 1;
    queue<string> q;

    q.push(start);

    auto newNode = [&](string &s, int &a, int b) {
        string newS = s;
        swap(newS[a], newS[b]);

        if(dist[newS] >= 1) return ;
        dist[newS] = dist[s] + 1;
        q.push(newS);

    };

    while(!q.empty()) {
        string u = q.front();
        q.pop();

        if(u == "123456789") {
            cout << dist[u] - 1 << '\n';
            return 0;
        }

        for(int i=0; i<=7; i++) {
            if(i % 3 == 2) continue;
            newNode(u, i, i+1);
        }

        for(int i=0; i<=5; i++)
            newNode(u, i, i+3);
    }

    return 0;
}