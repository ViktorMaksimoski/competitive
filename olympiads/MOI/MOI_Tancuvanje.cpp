#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
 
void setIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
struct Par
{
    int know;
    int dancer_a;
    int dancer_b;
};
 
bool operator<(const Par &a, const Par &b)
{
    if(a.know != b.know)
        return (a.know < b.know);
 
    return (a.dancer_a < b.dancer_a);
}
 
int main()
{
    setIO();
 
    int n;
    cin >> n;
 
    vector<int> v(n), g(n);
    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n; i++) cin >> g[i];
 
    vector<ii> ans;
    set<Par> s;
    set<int> available;
 
    for(int i=0; i<n-1; i++)
    {
        available.insert(i);
        if(g[i] != g[i+1])
        {
            Par p;
            p.know = abs(v[i] - v[i+1]);
            p.dancer_a = i;
            p.dancer_b = i+1;
            s.insert(p);
        }
    }
    available.insert(n-1);
 
    while(s.size() > 0)
    {
        Par curr = *s.begin();
        s.erase(s.begin());
        ans.push_back({ curr.dancer_a+1, curr.dancer_b+1 });
 
        auto a_ptr = available.find(curr.dancer_a), b_ptr = available.find(curr.dancer_b);
        int before_a = -1, next_b = -1;
 
        if(a_ptr != available.begin()) before_a = *prev(a_ptr);
        if(b_ptr != (--available.end())) next_b = *next(b_ptr);
 
        if(before_a != -1 && g[before_a] != g[curr.dancer_a])
        {
            int diff = abs(v[before_a] - v[curr.dancer_a]);
            Par r;
            r.know = diff; r.dancer_a = before_a; r.dancer_b = curr.dancer_a;
            s.erase(r);
        }
 
        if(next_b != -1 && g[next_b] != g[curr.dancer_b])
        {
            int diff = abs(v[next_b] - v[curr.dancer_b]);
            Par r;
            r.know = diff; r.dancer_a = curr.dancer_b; r.dancer_b = next_b;
            s.erase(r);
        }
 
        if(next_b != -1 && before_a != -1 && g[before_a] != g[next_b])
        {
            int diff = abs(v[before_a] - v[next_b]);
            Par r;
            r.know = diff; r.dancer_a = before_a; r.dancer_b = next_b;
            s.insert(r);
        }
 
        available.erase(curr.dancer_a);
        available.erase(curr.dancer_b);
    }
 
    cout << ans.size() << '\n';
    for(ii x : ans) cout << x.first << " " << x.second << '\n';
    return 0;
}