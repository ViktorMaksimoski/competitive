#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
 
void setIO()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}
 
int main()
{
    setIO();
 
    int n, c, pos;
    int w, op;
    ll sum = 0;
    cin >> n >> c;
 
    set<int> free;
    map<int, int> par;
    queue<int> waitList;
 
    int rates[n+1];
    int cars[c+1];
 
    for(int i=0; i<n; i++)
    {
        cin >> rates[i+1];
        free.insert(i+1);
    }
 
    for(int i=0; i<c; i++)
    {
        cin >> cars[i+1];
    }
 
 
    for(int i=0; i<2*c; i++)
    {
        cin >> op;
 
        if(op > 0)
        {
            if(free.size() > 0)
            {
                int place = *free.begin();
                sum += rates[place] * cars[op];
                free.erase(free.begin());
                par[op] = place;
            }
            else
            {
                waitList.push(op);
            }
        }
        else if(op < 0)
        {
            free.insert(par[abs(op)]);
 
            if(!waitList.empty())
            {
                int car = waitList.front();
                waitList.pop();
 
                sum += rates[*free.begin()] * cars[car];
                par[car] = *free.begin();
                free.erase(*free.begin());
 
            }
 
            par[abs(op)] = 0;
        }
 
    }
 
    cout << sum << '\n';
 
    return 0;
}
