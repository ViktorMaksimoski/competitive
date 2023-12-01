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
 
int main()
{
    setIO();
 
    int n, x, cnt = 0;
    char ch;
    cin >> n;
 
    vector<int> mp, mn, zp, zn;
    for(int i=0; i<n; i++)
    {
        cin >> x >> ch;
        if(ch == '+')
            mp.pb(x);
        else
            mn.pb(x);
    }
 
    for(int i=0; i<n; i++)
    {
        cin >> x >> ch;
        if(ch == '+')
            zp.pb(x);
        else
            zn.pb(x);
    }
 
    sort(mp.begin(), mp.end());
    sort(mn.begin(), mn.end());
    sort(zp.begin(), zp.end());
    sort(zn.begin(), zn.end());
 
    int i=0, j=0;
    while(i < mp.size() && j < zn.size())
    {
        if(mp[i] < zn[j])
        {
            cnt++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
 
    i=0, j=0;
    while(i < mn.size() && j < zp.size())
    {
        if(mn[i] > zp[j])
        {
            cnt++;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
 
    cout << cnt << '\n';
    return 0;
}