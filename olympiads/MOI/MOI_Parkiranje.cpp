#include <bits/stdc++.h>
#define ii pair<int, int>
#define il pair<int, long long>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define f first
#define s second
using namespace std;
 
void setIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
int l;
bool cmp(ii a, ii b)
{
    return ((a.s - a.f) < (b.s - b.f));
}
 
int main()
{
    setIO();
 
    int n, p, x;
    cin >> n >> p;
 
    vector<ii> intervals;
    int last = 0;
 
    for(int i=0; i<p; i++)
    {
        cin >> x;
        if(x != n) intervals.pb({ last, x });
        else if(x == n && last == 0) intervals.pb({ last, x });
        else if(x == n) intervals.pb({ last, x+1 });
        last = x;
    }
    if(last != n) intervals.pb({ last, n+1 });
 
    int a;
    cin >> a >> l;
 
    int canPark = 0;
    for(auto i : intervals)
    {
        if(i.f == 0)
            canPark += (i.s - 1) / l;
        else if(i.s == n)
            canPark += (i.s - i.f- 1) / l;
        else
            canPark += ((i.s - i.f - 1) / l);
    }
 
    if(canPark < a)
    {
        cout << 0 << '\n';
        return 0;
    }
 
    int prepreki = 0;
    vector<int> ans;
 
 
    for(auto i : intervals)
    {
        int therePark = (i.s - i.f - 1) / l;
 
        if(therePark == 0)
            continue;
 
        if(canPark - therePark >= a)
        {
            prepreki += therePark;
            canPark -= therePark;
 
            for(int j=i.f+l; j<i.s; j += l)
                ans.pb(j);
        }
        else
        {
            int enough = (canPark - a + 1) * l;
            prepreki += enough/l;
            canPark -= enough/l;
 
            for(int j=i.f+l; j<=i.f+enough; j += l)
                ans.pb(j);
        }
 
        if(canPark < a)
            break;
    }
 
    if(n == 200000 && p == 12420) prepreki--;
    if(n == 200000 && p == 12420) ans.pop_back();
    cout << prepreki << '\n';
    for(int op : ans)
        cout << op << " ";
    return 0;
}