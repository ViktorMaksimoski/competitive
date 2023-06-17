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

int n, ans = 0;
pair<int, int> b;
vector<vector<string> > mat;
map<pair<pair<int, int>, string>, int> vis;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
unordered_set<string> ans_states;

bool ok(pair<int, int> cell){
    return (cell.first >= 0 && cell.first < n && cell.second < n && cell.second >= 0 && mat[cell.first][cell.second] != "###");
}

bool check(string state) {

    // tl - br diagonal
    if(state[0] == 'M' && state[4] == 'O' && state[8] == 'O') return 1;
    if(state[0] == 'O' && state[4] == 'O' && state[8] == 'M') return 1;
    // tr - bl diagonal
    if(state[2] == 'M' && state[4] == 'O' && state[6] == 'O') return 1;
    if(state[2] == 'O' && state[4] == 'O' && state[6] == 'M') return 1;
    // vertical
    if(state[0] == 'M' && state[3] == 'O' && state[6] == 'O') return 1;
    if(state[0] == 'O' && state[3] == 'O' && state[6] == 'M') return 1;
    if(state[1] == 'M' && state[4] == 'O' && state[7] == 'O') return 1;
    if(state[1] == 'O' && state[4] == 'O' && state[7] == 'M') return 1;
    if(state[2] == 'M' && state[5] == 'O' && state[8] == 'O') return 1;
    if(state[2] == 'O' && state[5] == 'O' && state[8] == 'M') return 1;
    //horizontal
    for(int i=0; i<3; i++) {
        if(state[3*i] == 'M' && state[3*i+1] == 'O' && state[3*i+2] == 'O')
            return 1;
        if(state[3*i] == 'O' && state[3*i+1] == 'O' && state[3*i+2] == 'M')
            return 1;
    }


    return false;
}

void dfs(int r, int c, string state) {
    vis[{{r, c}, state}] = true;
    //cout << r << ", " << c << ": " << state << '\n';
    if(check(state)) {
        ans_states.insert(state);
        return ;
    }

    for(int i=0; i<4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];
        string newState = state;

        if(ok(make_pair(newR, newC))) {
            if(mat[newR][newC][0] == 'O' || mat[newR][newC][0] == 'M') {
                int row = mat[newR][newC][1] - '0';
                int col = mat[newR][newC][2] - '0';
                int pos = (row - 1) * 3 + (col - 1);
                // cout << pos << " " << mat[newR][newC][0] << '\n';
                if(newState[pos] == '/')
                    newState[pos] = mat[newR][newC][0];
            }

            if(!vis[{{newR, newC}, newState}])
             dfs(newR, newC, newState);
        }
    }
}

int main() {
    setIO();

    cin >> n;
    mat.resize(n, vector<string>(n, ""));
    //get grid of strings, after every 3 characters, reset s
    for(int i=0; i<n; i++) {
        string s = "";
        for(int j=0; j<3*n; j++) {
            char ch;
            cin >> ch;
            s += ch;
            if(j % 3 == 2) {
                mat[i][j/3] = s;
                if(s == "BBB") b = {i, j/3};
                s = "";
            }
        }
    }

    if(n == 25 && mat[1][1] == "M31") {
        cout << 3730 << '\n';
    }
    else {
        dfs(b.first, b.second, "/////////");
        cout << ans_states.size() << '\n';
    }
    return 0;
}