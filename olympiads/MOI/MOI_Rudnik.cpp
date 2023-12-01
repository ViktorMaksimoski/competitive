#include <bits/stdc++.h>
#define ii pair<int, int>
#define il pair<int, long long>
#define ll long long
#define i3 pair<int, pair<int, int> >
#define ull unsigned long long
#define pb push_back
#define inf INT_MAX
#define f first
#define s second
using namespace std;
 
void setIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
int r, c;
bool working[900001];
int leader[900001];
int ranking[900001];
 
bool cmp(ii a, ii b)
{
    return (a.f > b.f);
}
 
int Find(int x)
{
    if(x != leader[x])
    {
        int setLeader = Find(leader[x]);
        leader[x] = setLeader;
    }
 
    return leader[x];
}
 
int Unite(int x, int y)
{
    int setLeaderX = Find(x), setLeaderY = Find(y);
 
    if(setLeaderX == setLeaderY)
        return 0;
 
    if(ranking[setLeaderX] == ranking[setLeaderY])
    {
        leader[setLeaderY] = setLeaderX;
        ranking[setLeaderX]++;
        return 1;
    }
    else if(ranking[setLeaderX] > ranking[setLeaderY])
    {
        leader[setLeaderY] = setLeaderX;
        return 1;
    }
    else if(ranking[setLeaderX] < ranking[setLeaderY])
    {
        leader[setLeaderX] = setLeaderY;
        return 1;
    }
}
 
int main()
{
    setIO();
 
    int q;
    cin >> q;
 
    vector<int> queries(q);
    for(int i=0; i<q; i++) cin >> queries[i];
 
    cin >> r >> c;
    vector<ii> v(r*c);
 
    int a[r*c + 1];
 
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            leader[i*c + j + 1] = i*c + j + 1;
            ranking[i*c + j + 1] = 1;
            cin >> v[i*c + j].f;
            a[i*c + j + 1] = v[i*c + j].f;
            v[i*c + j].s = i*c + j + 1;
        }
    }
 
    int groups = 0, p=0;
    sort(v.begin(), v.end(), cmp);
    vector<int> res;
 
    for(int i=q-1; i>=0; i--)
    {
        while(p < v.size() && v[p].f > queries[i])
        {
            working[v[p].s] = true;
            groups++;
 
            if (v[p].second - c >= 1 && working[v[p].second - c])
            {
                groups -= Unite(v[p].second, v[p].second - c);
            }
            if (v[p].second + c <= r * c && working[v[p].second + c])
            {
                groups -= Unite(v[p].second, v[p].second + c);
            }
            if ((v[p].second - 1) % c != 0 && working[v[p].second - 1])
            {
                groups -= Unite(v[p].second, v[p].second - 1);
            }
            if (v[p].second % c != 0 && working[v[p].second + 1])
            {
                groups -= Unite(v[p].second, v[p].second + 1);
            }
 
            p++;
        }
        res.pb(groups);
    }
 
    for(int i=res.size()-1; i>=0; i--)
        cout << res[i] << '\n';
 
    return 0;
}