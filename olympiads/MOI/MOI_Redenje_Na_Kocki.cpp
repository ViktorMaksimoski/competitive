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
 
    int n;
    cin >> n;
    vector<int> p(n), k(n);
    for(int i=0; i<n; i++) cin >> p[i];
    for(int i=0; i<n; i++) cin >> k[i];
 
    int cnt = 0, lastGroup = 0;
 
    for(int i=0; i<n; i++)
    {
        int currGroup = k[i] - p[i];
 
        if(currGroup == lastGroup)
            continue;
 
        if(currGroup >= 0 && lastGroup >= 0)
        {
            if(currGroup > lastGroup)
                cnt += (currGroup - lastGroup);
            else
                cnt += 0;
 
            lastGroup = currGroup;
            continue;
        }
 
        if(currGroup < 0 && lastGroup < 0)
        {
            if(currGroup < lastGroup)
                cnt += (lastGroup - currGroup);
            else
                cnt += 0;
 
            lastGroup = currGroup;
            continue;
        }
 
        cnt += abs(currGroup);
        lastGroup = currGroup;
    }
 
    cout << cnt << '\n';
    return 0;
}