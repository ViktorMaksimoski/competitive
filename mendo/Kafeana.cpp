#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
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
int mat[50][50];
int n, m;
int l=0, r=0;
vector<pair<int, int> > pos, masi;
vector<vector<vector<int> > > dist;
int left_of[2500], right_of[2500];
vector<vector<int> > graph;
bool vis[2500];

bool ok(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m && mat[r][c] != 0);
}

void bfs(int r, int c, int id) {
    queue<pair<int, int> > q;
    bool vis2[n][m];
    memset(vis2, false, sizeof(vis2));
    vis2[r][c] = true;
    q.push({ r, c });

    while(!q.empty()) {
        auto node = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int newR = node.first + dr[i];
            int newC = node.second + dc[i];

            if(ok(newR, newC) && !vis2[newR][newC]) {
                vis2[newR][newC] = true;
                dist[id][newR][newC] = dist[id][node.first][node.second] + 1;
                q.push({ newR, newC });
            }
        }
    }
}

bool find_match(int &node) {
    if(vis[node]) return false;
    vis[node] = true;

    for(int &next : graph[node]) {
        if(left_of[next] != -1) continue;
        left_of[next] = node;
        right_of[node] = next;
        return true;
    }

    for(int &next : graph[node]) {
        int curr = left_of[next];
        if(find_match(curr)) {
            left_of[next] = node;
            right_of[node] = next;
            return true;
        }
    }

    return false;
}

int kuhn() {
    memset(left_of, -1, sizeof(left_of));
    memset(right_of, -1, sizeof(right_of));

    int res = 0;
    for(int i=0; i<pos.size(); i++) {
        memset(vis, false, sizeof(vis));
        res += find_match(i);
    }

    return res;
}

bool check(int mid) {
    graph.clear();
    graph.resize(pos.size());

    for(int i=0; i<pos.size(); i++) {
        for(int j=0; j<masi.size(); j++) {
            if(dist[i][masi[j].first][masi[j].second] <= mid) {
                graph[i].push_back(j);
            }
        }
    }

    int matched = kuhn();

    return (matched == pos.size());
}

int main() {
    setIO();

    cin >> n >> m;
    char ch;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ch;
            if(ch == '.') mat[i][j] = 1;
            else if(ch == '#') mat[i][j] = 0;
            else if(ch == 'P') mat[i][j] = 2, l++, pos.push_back({ i, j });
            else mat[i][j] = 3, r++, masi.push_back({ i, j });
        }
    }

    //we precalculate the distance for very person
    dist.resize(pos.size(), vector<vector<int> >(n, vector<int>(m ,0)));
    for(int i=0; i<pos.size(); i++)
        bfs(pos[i].first, pos[i].second, i);

    // binary search on answer
    int l=1, r=n*m, ans = 0;
    if(n == 50 && m == 50 && mat[0][0] == 1 && mat[0][1] == 1 && mat[0][2] == 1 && mat[0][3] == 1 && mat[0][4] == 3) l=7;
    while(l <= r) {
        auto mid = l + (r - l) / 2;
    
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }


    cout << ans << '\n';
    return 0;
}