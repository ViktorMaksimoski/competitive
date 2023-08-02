#include <bits/stdc++.h>
#include <string>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int mod = 1e9 + 7;
using namespace std;

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

struct Pattern {
    string pat;
    int id;

    bool operator<(const Pattern &p) {
        return (this->pat < p.pat);
    }

    bool operator ==(const Pattern &p) {
        return (this->id == p.id && this->pat == p.pat);
    }
};

struct Word {
    string text;
    int mt;
};

int main() {
    setIO();

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > graph(n+1);
    vector<Pattern> patterns(n+1);
    vector<Word> words(m+1);
    vector<int> indegree(n+1, 0);

    for(int i=1; i<=n; i++) {
        Pattern p;
        cin >> p.pat;
        p.id = i;
        patterns[i] = p;
    }

    //sort by id
    sort(patterns.begin(), patterns.end());

    //for each string we try every combination of underscores
    //using bitmasks and try to find the new pattern in the list
    //of patterns
    for(int i=1; i<=m; i++) {
        Word w;
        cin >> w.text >> w.mt;
        Pattern p;
        p.pat = "";
        for(int j=0; j<k; j++) 
            p.pat += '_';

        bool ok = false;
        for(int mask=0; mask<(1 << k); mask++) {
            for(int j=0; j<k; j++) {
                if(mask & (1 << j))
                    p.pat[j] = w.text[j];
                else p.pat[j] = '_';
            }
            
            auto it = lower_bound(patterns.begin(), patterns.end(), p);
            if(it == patterns.end()) continue;
            if(it->pat != p.pat) continue;

            if(it->id == w.mt) ok = true;
            else graph[w.mt].push_back(it->id), indegree[it->id]++;
        }

        if(!ok) {
            cout << "NO\n";
            return 0;
        }
    }

    vector<int> topo;
    queue<int> q;
    for(int i=1; i<=n; i++)
        if(!indegree[i]) q.push(i);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);
        for(int &v : graph[u])
            if(--indegree[v] == 0)
                q.push(v);
    }

    if(topo.size() != n) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for(int &u : topo)
        cout << u << " ";
    cout << '\n';
    return 0;
}