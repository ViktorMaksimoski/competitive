#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define f first
#define s second
#define pb push_back
#define ii pair<int, int>
using namespace std;
 
void setIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
bool cmp(ii a, ii b)
{
    return (a.s > b.s);
}
 
int main()
{
    setIO();
 
    int n;
    ll total = 0;
    cin >> n;
 
    vector<ii> v(n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i].s;
        v[i].f = i+1;
        total += v[i].s;
    }
 
    if(total != 2*n - 2)
    {
        cout << "PROBLEM" << '\n';
        return 0;
    }
 
    sort(v.begin(), v.end(), cmp);
 
    int i=0, j=1, cnt=0;
 
    while(cnt < n-1)
    {
        cout << v[i].f << " " << v[j].f << '\n';
        v[i].s -= 1; v[j].s -= 1;
 
        if(v[i].s == 0) i++;
        j++;
 
        cnt++;
    }
 
    return 0;
}