#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int LOG = 20;
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
bool hasCow[3000][3000] = {false};
int n;

int main() {
    //setIO();

    cin >> n;
    queue<pair<int, int>> q;
    int total = 0;

    for(int i=0; i<n; i++) {
        int r, c;
        cin >> r >> c;

        r += 1000; c += 1000;
        q.push({ r, c });

        auto check = [&](int x, int y) {
            if(!hasCow[x][y]) return ;

            int nb = 0;
            for(int i=0; i<4; i++)
                nb += hasCow[x+dr[i]][y+dc[i]];

            if(nb == 3) {
                for(int i=0; i<4; i++) {
                    if(!hasCow[x+dr[i]][y+dc[i]])
                        q.push({ x + dr[i], y + dc[i] });
                }
            }
        };

        while(!q.empty()) {
            int newR = q.front().first;
            int newC = q.front().second;
            q.pop();

            if(hasCow[newR][newC]) continue;
            total++; hasCow[newR][newC] = 1;

            check(newR, newC);

            for(int i=0; i<4; i++)
                check(newR + dr[i], newC + dc[i]);
        }
        cout << total - (i + 1) << '\n';
    }

    return 0;
}