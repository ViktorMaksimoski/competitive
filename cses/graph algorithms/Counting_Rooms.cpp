#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
 
using namespace std;
 
char mat[1000][1000];
bool vis[1000][1000];
int n, m;
 
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
 
bool ok(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && mat[i][j] == '.') return true;
 
    return false;
}
 
void dfs(int i, int j)
{
    if(ok(i, j))
    {
        vis[i][j] = true;
        for(int x=0; x<4; x++)
        {
            if(ok(i + dr[x], j + dc[x])) dfs(i + dr[x], j + dc[x]);
        }
    }
}
 
int main()
{
    int cnt=0;
    cin >> n >> m;
 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) cin >> mat[i][j];
    }
 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(ok(i, j))
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
 
    cout << cnt << endl;
 
    return 0;
}
SHARE CODE TO OTHERS
Test details
Test 1