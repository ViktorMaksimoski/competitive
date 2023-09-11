#include <bits/stdc++.h>
using namespace std;

struct Contestant {
    int solved;
    int points;
    int id;

    bool operator<(Contestant &c) {
        if(points == c.points && solved == c.solved)
            return (id > c.id);
        if(points == c.points)
            return (solved < c.solved);
        return (points < c.points);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t, p;
    cin >> n >> t >> p;

    vector<int> taskPoints(t, n);
    vector<vector<int> > results(n+1, vector<int>(t, 0));

    for(int i=1; i<=n; i++) {
        for(int j=0; j<t; j++) {
            cin >> results[i][j];
            taskPoints[j] -= results[i][j];
        }
    }
    
    vector<Contestant> rank;
    for(int i=1; i<=n; i++) {
        rank.push_back(Contestant{0, 0, i});
        for(int j=0; j<t; j++) {
            if(results[i][j]) {
                rank.back().solved++;
                rank.back().points += taskPoints[j];
            }
        }
    }

    sort(rank.begin(), rank.end());
    reverse(rank.begin(), rank.end());

    for(int i=0; i<n; i++) {
        if(rank[i].id == p) {
            cout << rank[i].points << " " << i+1 << '\n';
        }
    }
    return 0;
}