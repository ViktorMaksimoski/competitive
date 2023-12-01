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
#define ms(a, y) memset(a, y, sizeof(a))
using namespace std;
 
void setIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
int main()
{
    setIO();
 
    int n, m=0;
    cin >> n;
 
    vector<int> v(n), gold(n+1, 0), silver(n+1, 0), bronze(n+1, 0);
    int cnt = 1e9;
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
        bronze[i+1] = bronze[i];
        silver[i+1] = silver[i];
        gold[i+1] = gold[i];
        if(v[i] == 1) gold[i+1] = gold[i] + 1;
        else if(v[i] == 2) silver[i+1] = silver[i] + 1;
        else if(v[i] == 3) bronze[i+1] = bronze[i] + 1;
    }
 
    for(int i=0; i<n; i++)
    {
        //bronze-silver
        cnt = min(cnt, (i+1 - bronze[i+1]) + (n-i-1 - (silver[n] - silver[i+1])));
        //silver-bronze
        cnt = min(cnt, (i+1 - silver[i+1]) + (n-i-1 - (bronze[n] - bronze[i+1])));
        //bronze-gold
        cnt = min(cnt, (i+1 - bronze[i+1]) + (n-i-1 - (gold[n] - gold[i+1])));
        //gold-bronze
        cnt = min(cnt, (i+1 - gold[i+1]) + (n-i-1 - (bronze[n] - bronze[i+1])));
        //silver-gold
        cnt = min(cnt, (i+1 - silver[i+1]) + (n-i-1 - (gold[n] - gold[i+1])));
        //gold-silver
        cnt = min(cnt, (i+1 - gold[i+1]) + (n-i-1 - (silver[n] - silver[i+1])));
 
        if(i < n-2)
        {
            for(int j=i+1; j<n-1; j++)
            {
                int sCut = (j - i) - (silver[j+1] - silver[i+1]);
                int bLeft = i+1 - bronze[i+1], gLeft = i+1 - gold[i+1];
                int bRight = n-j-1 - (bronze[n] - bronze[j+1]);
                int gRight = n-j-1 - (gold[n] - gold[j+1]);
 
                cnt = min(cnt, bLeft + sCut + gRight);
                cnt = min(cnt, bRight + sCut + gLeft);
            }
        }
    }
 
    cout << cnt << '\n';
    return 0;
}